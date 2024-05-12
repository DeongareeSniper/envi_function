/*
作者：邱子粤
Email：782381967@qq.com
主题：ENVI光谱函数库
时间：2024-01-15

备注：传入参数为像素DM值
*/

#include "../include/SpectralIndices.h"
using namespace std;

// 为避免在判断中与窄频段冲突，下列波长为该频段中心波长（nm）加1
#define BLUE 471
#define GREEN 551
#define RED 651
#define NIR 861
#define SWIR1 1651
#define SWIR2 2221
#define VREI2 716
#define RENDVI 751
#define ARVI 801

// float转化为6位小数，并四舍五入
float transform_to_six_decimal_places(float x)
{
    float a, b;
    a = x * 1000000;
    b = round(a) / 1000000;
    return b;
}

// 判断所寻找的中心波段，确定该波段范围，并判断该波段是否符合范围要求
int determine_band_range(float value_of_band, int value_of_needed_band)
{
    switch (value_of_needed_band)
    {
    case 445:
        if (value_of_band > 435 && value_of_band < 448)
            return 1;
        break;
    case 450:
        if (value_of_band > 425 && value_of_band < 475)
            return 1;
        break;
    case BLUE: // 470
        if (value_of_band > 400 && value_of_band < 500)
            return 1;
        break;
    case 500:
        if (value_of_band > 480 && value_of_band < 520)
            return 1;
        break;
    case 510:
        if (value_of_band > 500 && value_of_band < 515)
            return 1;
        break;
    case 531:
        if (value_of_band > 525 && value_of_band < 550)
            return 1;
        break;
    case 550:
        if (value_of_band > 540 && value_of_band < 560)
            return 1;
        break;
    case GREEN: // 550
        if (value_of_band > 500 && value_of_band < 600)
            return 1;
        break;
    case 570:
        if (value_of_band > 560 && value_of_band < 575)
            return 1;
        break;
    case RED: // 650
        if (value_of_band > 600 && value_of_band < 700)
            return 1;
        break;
    case 670:
        if (value_of_band > 650 && value_of_band < 690)
            return 1;
        break;
    case 699:
        if (value_of_band > 650 && value_of_band < 735)
            return 1;
        break;
    case 700:
        if (value_of_band > 680 && value_of_band < 730)
            return 1;
        break;
    case 705:
        if (value_of_band > 697 && value_of_band < 708)
            return 1;
        break;
    case 715:
        if (value_of_band > 714 && value_of_band < 716)
            return 1;
        break;
    case VREI2: // 715
        if (value_of_band > 710 && value_of_band < 719)
            return 1;
        break;
    case 720:
        if (value_of_band > 718 && value_of_band < 722)
            return 1;
        break;
    case 726:
        if (value_of_band > 725 && value_of_band < 727)
            return 1;
        break;
    case 734:
        if (value_of_band > 730 && value_of_band < 736)
            return 1;
        break;
    case 740:
        if (value_of_band > 730 && value_of_band < 750)
            return 1;
        break;
    case 747:
        if (value_of_band > 742 && value_of_band < 748)
            return 1;
        break;
    case 750:
        if (value_of_band > 730 && value_of_band < 780)
            return 1;
        break;
    case RENDVI: // 750
        if (value_of_band > 730 && value_of_band < 760)
            return 1;
        break;
    case 795:
        if (value_of_band > 720 && value_of_band < 800)
            return 1;
        break;
    case 800:
        if (value_of_band > 780 && value_of_band < 865)
            return 1;
        break;
    case ARVI: // 800
        if (value_of_band > 750 && value_of_band < 870)
            return 1;
        break;
    case 819:
        if (value_of_band > 815 && value_of_band < 824)
            return 1;
        break;
    case 857:
        if (value_of_band > 854 && value_of_band < 860)
            return 1;
        break;
    case 860:
        if (value_of_band > 841 && value_of_band < 876)
            return 1;
        break;
    case NIR: // 860
        if (value_of_band > 760 && value_of_band < 960)
            return 1;
        break;
    case 900:
        if (value_of_band > 860 && value_of_band < 910)
            return 1;
        break;
    case 970:
        if (value_of_band > 965 && value_of_band < 975)
            return 1;
        break;
    case 990:
        if (value_of_band > 830 && value_of_band < 995)
            return 1;
        break;
    case 1241:
        if (value_of_band > 1230 && value_of_band < 1250)
            return 1;
        break;
    case 1510:
        if (value_of_band > 1500 && value_of_band < 1515)
            return 1;
        break;
    case 1599:
        if (value_of_band > 1590 && value_of_band < 1620)
            return 1;
        break;
    case 1640:
        if (value_of_band > 1628 && value_of_band < 1652)
            return 1;
        break;
    case 1649:
        if (value_of_band > 1645 && value_of_band < 1655)
            return 1;
        break;
    case SWIR1: // 1650
        if (value_of_band > 1550 && value_of_band < 1750)
            return 1;
        break;
    case 1680:
        if (value_of_band > 1670 && value_of_band < 1690)
            return 1;
        break;
    case 1754:
        if (value_of_band > 1750 && value_of_band < 1758)
            return 1;
        break;
    case 2000:
        if (value_of_band > 1980 && value_of_band < 2040)
            return 1;
        break;
    case 2100:
        if (value_of_band > 2085 && value_of_band < 2110)
            return 1;
        break;
    case 2130:
        if (value_of_band > 2105 && value_of_band < 2155)
            return 1;
        break;
    case 2200:
        if (value_of_band > 2170 && value_of_band < 2220)
            return 1;
        break;
    case SWIR2: // 2220
        if (value_of_band > 2080 && value_of_band < 2350)
            return 1;
        break;
    }
    return 0;
};

// 寻找中心波段,返回查找的波段的编号,后续还需要确定是否在波段范围内
int find_central_band(float *value_array_of_all_band, int size_of_all_band, int value_of_needed_band)
{
    int i, a;
    float j, k, x, y;
    int band_number = -1;
    int sub_value = 1000;
    a = value_of_needed_band;
    if (a == BLUE || a == RED || a == GREEN ||
        a == NIR || a == SWIR1 || a == SWIR2 ||
        a == VREI2 || a == RENDVI || a == ARVI)
    {
        a--;
    }
    for (i = 0; i < size_of_all_band; i++)
    {
        x = value_array_of_all_band[i];
        y = determine_band_range(x, value_of_needed_band);
        if (y == 1)
        {
            j = x - (float)a;
            k = fabs(j);
            if (k < sub_value)
            {
                band_number = i;
            }
        }
    }
    return band_number;
}

// 光谱指数计算模块对外接口
void spectral_index_calculation(int ***raw_data, int x, int y, int z, float *value_array_of_all_band,
                                SpectralIndices spectralindices_index, float **result)
{
}

// testing
int main(int argc, const char **argv)
{
    int green, yellow, blue;
    green = 657;
    yellow = 499;
    blue = 124;
    float wvii = transform_to_six_decimal_places(worldview_new_iron_index(green, yellow, blue));
    cout << "WV_II is " << wvii << endl;
    return 0;
}
