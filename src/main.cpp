/*
作者：邱子粤
Email：782381967@qq.com
主题：ENVI光谱函数库
时间：2024-01-15

备注：传入参数单位均为
*/

#include <iostream>
#include <cmath>
#include "../include/SpectralIndices.h"
using namespace std;
// Burn Indices Background
float burn_area_index(int red, int nir)
{
    float a, b;
    float bai;
    a = pow(0.1 - (float)red, 2);
    b = pow(0.06 - (float)nir, 2);
    bai = 1 / (a + b);
    return bai;
}

float normalized_burn_ratio(int swir, int nir)
{
    float a, b;
    float nbr;
    a = nir - swir;
    b = nir + swir;
    nbr = a / b;
    return nbr;
}

float normalized_burn_ratio_thermal_1(int swir, int nir, int thermal)
{
    float a, b;
    float nbrt1;
    a = nir - swir * (thermal / 1000);
    b = nir + swir * (thermal / 1000);
    nbrt1 = a / b;
    return nbrt1;
}

// Geology Indices Background
float clay_minerals_ratio(int swir1, int swir2)
{
    float cmr;
    cmr = swir1 / swir2;
    return cmr;
}

float ferrous_minerals_ratio(int swir, int nir)
{
    float fmr;
    fmr = swir / nir;
    return fmr;
}

float iron_oxide_ratio(int red, int blue)
{
    float ior;
    ior = red / blue;
    return ior;
}

float worldview_new_iron_index(int green, int yellow, int blue)
{
    float wvii;
    wvii = ((float)green - (float)yellow) / ((float)blue * 1000);
    cout << "WV-II is " << wvii << endl;
    return wvii;
}

float worldview_soil_index(int green, int yellow)
{
    float wvsi;
    wvsi = (green - yellow) / (green + yellow);
    return wvsi;
}

// Miscellaneous Indices Background
float modified_normalized_difference_water_index(int green, int swir)
{
    float mndwi;
    mndwi = (green - swir) / (green + swir);
    return mndwi;
}

float normalized_difference_built_up_index(int swir, int nir)
{
    float ndbi;
    ndbi = (swir - nir) / (swir + nir);
    return ndbi;
}

float normalized_difference_mud_index(int p795, int p990)
{
    float ndmi;
    ndmi = (p795 - p990) / (p795 + p990);
    return ndmi;
}

float normalized_difference_snow_index(int green, int nir)
{
    float ndsi;
    ndsi = (green - nir) / (green + nir);
    return ndsi;
}

float worldview_built_up_index(int coastal, int red_edge)
{
    float wvbi;
    wvbi = (coastal - red_edge) / (coastal + red_edge);
    return wvbi;
}

float worldView_non_homogeneous_feature_difference(int red_edge, int coastal)
{
    float wvnhfd;
    wvnhfd = (red_edge - coastal) / (red_edge + coastal);
    return wvnhfd;
}

float worldview_water_index(int coastal, int nir2)
{
    float wvwi;
    wvwi = (coastal - nir2) / (coastal + nir2);
    return wvwi;
}

// float转化为6位小数，并四舍五入
float transform_to_six_decimal_places(float x)
{
    float a, b;
    a = x * 1000000;
    b = round(a) / 1000000;
    return b;
}

// 判断所寻找的中心波段，确定该波段范围，并判断该波段是否符合范围要求
int determine_band_range(float value_of_band, int value_of_needed_band) {
    // switch(value_of_needed_band)
    // {
    //     case
    // }
};

// 寻找中心波段,返回查找的波段的编号,后续还需要确定是否在波段范围内
int find_central_band(float *value_array_of_all_band, int size_of_all_band, int value_of_needed_band)
{
    int i;
    float j, k, x, y;
    int band_number = -1;
    int sub_value = 1000;
    for (i = 0; i < size_of_all_band; i++)
    {
        x = value_array_of_all_band[i];
        y = determine_band_range(x, value_of_needed_band);
        if (y == 1)
        {
            j = x - (float)value_of_needed_band;
            k = fabs(j);
            if (k < sub_value)
            {
                band_number = i;
            }
        }
    }
    return band_number;
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
