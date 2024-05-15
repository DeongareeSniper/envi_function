
#include "../include/SpectralIndices_math.h"
using namespace std;

// float转化为6位小数，并四舍五入
float transform_to_six_decimal_places(float x)
{
    float a, b;
    a = x * 1000000;
    b = round(a) / 1000000;
    return b;
}

int determine_band_range(float value_of_band, int value_of_needed_band)
{
    switch (value_of_needed_band)
    {
    case Coastal:
        if (value_of_band >= 400 && value_of_band <= 450)
            return 1;
        break;
    case 445:
        if (value_of_band >= 435 && value_of_band <= 448)
            return 1;
        break;
    case 450:
        if (value_of_band >= 425 && value_of_band <= 475)
            return 1;
        break;
    case BLUE: // 470
        if (value_of_band >= 400 && value_of_band <= 500)
            return 1;
        break;
    case 500:
        if (value_of_band >= 480 && value_of_band <= 520)
            return 1;
        break;
    case 510:
        if (value_of_band >= 500 && value_of_band <= 515)
            return 1;
        break;
    case 531:
        if (value_of_band >= 525 && value_of_band <= 550)
            return 1;
        break;
    case 550:
        if (value_of_band >= 540 && value_of_band <= 560)
            return 1;
        break;
    case GREEN: // 550
        if (value_of_band >= 500 && value_of_band <= 600)
            return 1;
        break;
    case 570:
        if (value_of_band >= 560 && value_of_band <= 575)
            return 1;
        break;
    case RED: // 650
        if (value_of_band >= 600 && value_of_band <= 700)
            return 1;
        break;
    case YELLOW:
        if (value_of_band >= 585 && value_of_band <= 625)
            return 1;
        break;
    case 670:
        if (value_of_band >= 650 && value_of_band <= 690)
            return 1;
        break;
    case 699:
        if (value_of_band >= 650 && value_of_band <= 735)
            return 1;
        break;
    case 700:
        if (value_of_band >= 680 && value_of_band <= 730)
            return 1;
        break;
    case 705:
        if (value_of_band >= 697 && value_of_band <= 708)
            return 1;
        break;
    case 715:
        if (value_of_band >= 714 && value_of_band <= 716)
            return 1;
        break;
    case p715_wide: // 715
        if (value_of_band >= 710 && value_of_band <= 719)
            return 1;
        break;
    case 720:
        if (value_of_band >= 718 && value_of_band <= 722)
            return 1;
        break;
    case Red_Edge:
        if (value_of_band >= 705 && value_of_band <= 745)
            return 1;
        break;
    case 726:
        if (value_of_band >= 725 && value_of_band <= 727)
            return 1;
        break;
    case 734:
        if (value_of_band >= 730 && value_of_band <= 736)
            return 1;
        break;
    case 740:
        if (value_of_band >= 730 && value_of_band <= 750)
            return 1;
        break;
    case 747:
        if (value_of_band >= 742 && value_of_band <= 748)
            return 1;
        break;
    case 750:
        if (value_of_band >= 730 && value_of_band <= 780)
            return 1;
        break;
    case p750_narrow: // 750
        if (value_of_band >= 730 && value_of_band <= 760)
            return 1;
        break;
    case 795:
        if (value_of_band >= 720 && value_of_band <= 800)
            return 1;
        break;
    case 800:
        if (value_of_band >= 780 && value_of_band <= 865)
            return 1;
        break;
    case p800_wide: // 800
        if (value_of_band >= 750 && value_of_band <= 870)
            return 1;
        break;
    case 819:
        if (value_of_band >= 815 && value_of_band <= 824)
            return 1;
        break;
    case 857:
        if (value_of_band >= 854 && value_of_band <= 860)
            return 1;
        break;
    case 860:
        if (value_of_band >= 841 && value_of_band <= 876)
            return 1;
        break;
    case NIR: // 860
        if (value_of_band >= 760 && value_of_band <= 960)
            return 1;
        break;
    case 900:
        if (value_of_band >= 860 && value_of_band <= 910)
            return 1;
        break;
    case NIR2:
        if (value_of_band >= 860 && value_of_band <= 1040)
            return 1;
        break;
    case 970:
        if (value_of_band >= 965 && value_of_band <= 975)
            return 1;
        break;
    case 990:
        if (value_of_band >= 830 && value_of_band <= 995)
            return 1;
        break;
    case Thermal:
        if (value_of_band >= 1040 && value_of_band <= 1250)
            return 1;
        break;
    case 1241:
        if (value_of_band >= 1230 && value_of_band <= 1250)
            return 1;
        break;
    case 1510:
        if (value_of_band >= 1500 && value_of_band <= 1515)
            return 1;
        break;
    case 1599:
        if (value_of_band >= 1590 && value_of_band <= 1620)
            return 1;
        break;
    case 1640:
        if (value_of_band >= 1628 && value_of_band <= 1652)
            return 1;
        break;
    case 1649:
        if (value_of_band >= 1645 && value_of_band <= 1655)
            return 1;
        break;
    case SWIR1: // 1650
        if (value_of_band >= 1550 && value_of_band <= 1750)
            return 1;
        break;
    case 1680:
        if (value_of_band >= 1670 && value_of_band <= 1690)
            return 1;
        break;
    case 1754:
        if (value_of_band >= 1750 && value_of_band <= 1758)
            return 1;
        break;
    case 2000:
        if (value_of_band >= 1980 && value_of_band <= 2040)
            return 1;
        break;
    case 2100:
        if (value_of_band >= 2085 && value_of_band <= 2110)
            return 1;
        break;
    case 2130:
        if (value_of_band >= 2105 && value_of_band <= 2155)
            return 1;
        break;
    case 2200:
        if (value_of_band >= 2170 && value_of_band <= 2220)
            return 1;
        break;
    case SWIR2: // 2220
        if (value_of_band >= 2080 && value_of_band <= 2350)
            return 1;
        break;
    }
    return 0;
}

// 寻找中心波段,返回查找的波段的编号,后续还需要确定是否在波段范围内
int find_central_band(float *value_array_of_all_band, int size_of_all_band, int value_of_needed_band)
{
    int i, a;
    float j, k, x, y;
    int band_number = -1;
    float sub_value = 1000;
    a = value_of_needed_band;
    if (a == BLUE || a == RED || a == GREEN ||
        a == NIR || a == SWIR1 || a == SWIR2 ||
        a == p715_wide || a == p750_narrow || a == p800_wide)
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
                sub_value = k;
            }
        }
    }
    return band_number;
}
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

float normalized_burn_ratio(int swir2, int nir)
{
    float a, b;
    float nbr;
    a = (float)nir - (float)swir2;
    b = (float)nir + (float)swir2;
    nbr = a / b;
    return nbr;
}

////////////////////////////////////////////////////////////////
// 没有thermal参数
float normalized_burn_ratio_thermal_1(int swir2, int nir, int thermal)
{
    float a, b;
    float nbrt1;
    a = (float)nir - (float)swir2 * ((float)thermal / 1000);
    b = (float)nir + (float)swir2 * ((float)thermal / 1000);
    nbrt1 = a / b;
    return nbrt1;
}
////////////////////////////////////////////////////////////////

// Geology Indices Background
float clay_minerals_ratio(int swir1, int swir2)
{
    float cmr;
    cmr = (float)swir1 / (float)swir2;
    return cmr;
}

float ferrous_minerals_ratio(int swir1, int nir)
{
    float fmr;
    fmr = (float)swir1 / (float)nir;
    return fmr;
}

float iron_oxide_ratio(int red, int blue)
{
    float ior;
    ior = (float)red / (float)blue;
    return ior;
}

float worldview_new_iron_index(int green, int yellow, int blue)
{
    float wvii;
    wvii = ((float)green - (float)yellow) / ((float)blue * 1000);
    return wvii;
}

float worldview_soil_index(int green, int yellow)
{
    float wvsi;
    wvsi = ((float)green - (float)yellow) / ((float)green + (float)yellow);
    return wvsi;
}

// Miscellaneous Indices Background
float modified_normalized_difference_water_index(int green, int swir1)
{
    float mndwi;
    mndwi = ((float)green - (float)swir1) / ((float)green + (float)swir1);
    return mndwi;
}

float normalized_difference_built_up_index(int swir1, int nir)
{
    float ndbi;
    ndbi = ((float)swir1 - (float)nir) / ((float)swir1 + (float)nir);
    return ndbi;
}

float normalized_difference_mud_index(int p795, int p990)
{
    float ndmi;
    ndmi = ((float)p795 - (float)p990) / ((float)p795 + (float)p990);
    return ndmi;
}

float normalized_difference_snow_index(int green, int nir)
{
    float ndsi;
    ndsi = ((float)green - (float)nir) / ((float)green + (float)nir);
    return ndsi;
}

float worldview_built_up_index(int coastal, int red_edge)
{
    float wvbi;
    wvbi = ((float)coastal - (float)red_edge) / ((float)coastal + (float)red_edge);
    return wvbi;
}

float worldView_non_homogeneous_feature_difference(int red_edge, int coastal)
{
    float wvnhfd;
    wvnhfd = ((float)red_edge - (float)coastal) / ((float)red_edge + (float)coastal);
    return wvnhfd;
}

float worldview_water_index(int coastal, int nir2)
{
    float wvwi;
    wvwi = ((float)coastal - (float)nir2) / ((float)coastal + (float)nir2);
    return wvwi;
}

// Vegetation Indices Background
float atmospherically_resistant_vegetation_index(int nir, int red, int blue)
{
    float arvi;
    float a, b;
    a = (float)nir - ((float)red - ((float)blue - (float)red));
    b = (float)nir + ((float)red - ((float)blue - (float)red));
    arvi = a / b;
    return arvi;
}

float difference_vegetation_index(int nir, int red)
{
    float dvi;
    dvi = (float)nir - (float)red;
    return dvi;
}

float enhanced_vegetation_index(int nir, int red, int blue)
{
    float evi;
    float a, b;
    a = 2.5 * ((float)nir - (float)red);
    b = (float)nir + 6 * (float)red - 7.5 * (float)blue + 1;
    evi = a / b;
    return evi;
}

float global_environmental_monitoring_index(int nir, int red)
{
    float gemi;
    float a, b, c;
    a = 2 * ((float)nir * (float)nir - (float)red * (float)red) + 1.5 * (float)nir + 0.5 * (float)red;
    b = (float)nir + (float)red + 0.5;
    c = a / b;
    a = (float)red - 0.125;
    b = 1 - (float)red;
    gemi = c * (1 - 0.25 * c) - (a / b);
    return gemi;
}

float green_atmospherically_resistant_index(int nir, int red, int green, int blue)
{
    float gari;
    float a, b;
    a = (float)nir - ((float)green - 1.7 * ((float)blue - (float)red));
    b = (float)nir + ((float)green - 1.7 * ((float)blue - (float)red));
    gari = a / b;
    return gari;
}

float green_difference_vegetation_index(int nir, int green)
{
    float gdvi;
    gdvi = (float)nir - (float)green;
    return gdvi;
}

float green_normalized_difference_vegetation_index(int nir, int green)
{
    float gndvi;
    float a, b;
    a = (float)nir - (float)green;
    b = (float)nir + (float)green;
    gndvi = a / b;
    return gndvi;
}

float green_ratio_vegetation_index(int nir, int green)
{
    float grvi;
    grvi = (float)nir / (float)green;
    return grvi;
}

// 没有TM卫星,暂时占位
float green_vegetation_index()
{
    return 0;
}

float infrared_percentage_vegetation_index(int nir, int red)
{
    float ipvi;
    ipvi = (float)nir / ((float)nir + (float)red);
    return ipvi;
}

float leaf_area_index(int nir, int red, int blue)
{
    float lai, evi;
    evi = enhanced_vegetation_index(nir, red, blue);
    lai = 3.618 * evi - 0.118;
    return lai;
}

float modified_non_linear_index(int nir, int red)
{
    float mnli, a, b;
    a = ((float)nir * (float)nir - (float)red) * 1.5;
    b = (float)nir * (float)nir + (float)red + 0.5;
    mnli = a / b;
    return mnli;
}

float modified_simple_ratio(int nir, int red)
{
    float msr, a, b, c;
    a = ((float)nir / (float)red) - 1;
    c = sqrt((float)nir / (float)red);
    b = c + 1;
    msr = a / b;
    return msr;
}

float non_linear_index(int nir, int red)
{
    float nli, a, b;
    a = (float)nir * (float)nir - (float)red;
    b = (float)nir * (float)nir + (float)red;
    nli = a / b;
    return nli;
}

float normalized_difference_vegetation_index(int nir, int red)
{
    float ndvi, a, b;
    a = (float)nir - (float)red;
    b = (float)nir + (float)red;
    ndvi = a / b;
    return ndvi;
}

float optimized_soil_adjusted_vegetation_index(int nir, int red)
{
    float osavi, a, b;
    a = 1.5 * ((float)nir - (float)red);
    b = (float)nir + (float)red + 0.16;
    osavi = a / b;
    return osavi;
}

float renormalized_difference_vegetation_index(int nir, int red)
{
    float rdvi, a, b, c;
    a = (float)nir - (float)red;
    c = (float)nir + (float)red;
    b = sqrt(c);
    rdvi = a / b;
    return rdvi;
}

float soil_adjusted_vegetation_index(int nir, int red)
{
    float savi, a, b;
    a = 1.5 * ((float)nir - (float)red);
    b = (float)nir + (float)red + 0.5;
    savi = a / b;
    return savi;
}

float simple_ratio(int nir, int red)
{
    float sr;
    sr = (float)nir / (float)red;
    return sr;
}

float Transformed_difference_vegetation_index(int nir, int red)
{
    float tdvi, a, b;
    a = ((float)nir - (float)red) / ((float)nir + (float)red);
    b = a + 0.5;
    tdvi = sqrt(b);
    return tdvi;
}

float visible_atmospherically_resistant_index(int red, int green, int blue)
{
    float vari;
    vari = ((float)green - (float)red) / ((float)green + (float)red - (float)blue);
    return vari;
}

float worldview_improved_vegetative_index(int nir2, int red)
{
    float wvvi;
    wvvi = ((float)nir2 - (float)red) / ((float)nir2 + (float)red);
    return wvvi;
}

float modified_chlorophyll_absorption_ratio_index(int p550, int p670, int p700)
{
    float mcari;
    mcari = (((float)p700 - (float)p670) - 0.2 * ((float)p700 - (float)p550)) * ((float)p700 / (float)p670);
    return mcari;
}

float modified_chlorophyll_absorption_ratio_index_improved(int p550, int p670, int p800)
{
    float mcari2, a, b, c, d;
    a = 1.5 * (2.5 * ((float)p800 - (float)p670) - 1.3 * ((float)p800 - (float)p550));
    d = sqrt((float)p670);
    c = (2 * (float)p800 + 1) * (2 * (float)p800 + 1) - (6 * (float)p800 - 5 * d) - 0.5;
    b = sqrt(c);
    mcari2 = a / b;
    return mcari2;
}

float modified_red_edge_normalized_difference_vegetation_index(int p445, int p705, int p750)
{
    float mrendvi, a, b;
    a = (float)p750 - (float)p705;
    b = (float)p750 + (float)p705 - 2 * (float)p445;
    mrendvi = a / b;
    return mrendvi;
}

float modified_red_edge_simple_ratio(int p445, int p705, int p750)
{
    float mresr;
    mresr = ((float)p750 - (float)p445) / ((float)p705 - (float)p445);
    return mresr;
}

float modified_triangular_vegetation_index(int p550, int p670, int p800)
{
    float mtvi;
    mtvi = 1.2 * (1.2 * ((float)p800 - (float)p550) - 2.5 * ((float)p670 - (float)p550));
    return mtvi;
}

float modified_triangular_vegetation_index_improved(int p550, int p670, int p800)
{
    float mtvi2, a, b, c, d;
    a = 1.5 * (1.2 * ((float)p800 - (float)p550) - 2.5 * ((float)p670 - (float)p550));
    c = sqrt((float)p670);
    d = (2 * (float)p800 + 1) * (2 * (float)p800 + 1) - (6 * (float)p800 - 5 * c) - 0.5;
    b = sqrt(d);
    mtvi2 = a / b;
    return mtvi2;
}

float red_edge_normalized_difference_vegetation_index(int p705, int p750)
{
    float rendvi;
    rendvi = ((float)p750 - (float)p705) / ((float)p750 + (float)p705);
    return rendvi;
}

// 690 nm至740 nm光谱中植被红边区域反射率最大导数的波长,暂时未实现，占位
float red_edge_position_index()
{
    return 0;
}

float transformed_chlorophyll_absorption_reflectance_index(int p550, int p670, int p700)
{
    float tcari;
    tcari = 3 * (((float)p700 - (float)p670) - 0.2 * ((float)p700 - (float)p550) * ((float)p700 / (float)p670));
    return tcari;
}

float triangular_vegetation_index(int p550, int p670, int p750)
{
    float tvi;
    tvi = 0.5 * (120 * ((float)p750 - (float)p550) - 200 * ((float)p670 - (float)p550));
    return tvi;
}

float vogelmann_red_edge_index_1(int p720, int p740)
{
    float vrei1;
    vrei1 = (float)p740 / (float)p720;
    return vrei1;
}

float vogelmann_red_edge_index_2(int p715, int p726, int p734, int p747)
{
    float vrei2;
    vrei2 = ((float)p734 - (float)p747) / ((float)p715 - (float)p726);
    return vrei2;
}

float normalized_difference_nitrogen_index(int p1510, int p1680)
{
    float ndni, a, b;
    a = log(1 / (float)p1510);
    b = log(1 / (float)p1680);
    ndni = (a - b) / (a + b);
    return ndni;
}

float moisture_stress_index(int p1599, int p819)
{
    float msi;
    msi = (float)p1599 / (float)p819;
    return msi;
}

float normalized_difference_infrared_index(int p819, int p1649)
{
    float ndii;
    ndii = ((float)p819 - (float)p1649) / ((float)p819 + (float)p1649);
    return ndii;
}

float normalized_difference_water_index(int p857, int p1241)
{
    float ndwi;
    ndwi = ((float)p857 - (float)p1241) / ((float)p857 + (float)p1241);
    return ndwi;
}

float normalized_multi_band_drought_index(int p860, int p1640, int p2130)
{
    float ndmi, a, b;
    a = (float)p860 - ((float)p1640 - (float)p2130);
    b = (float)p860 + ((float)p1640 - (float)p2130);
    ndmi = a / b;
    return ndmi;
}

float water_band_index(int p900, int p970)
{
    float wbi;
    wbi = (float)p970 / (float)p900;
    return wbi;
}

float normalized_difference_lignin_index(int p1680, int p1754)
{
    float ndli, a, b;
    a = log(1 / (float)p1754);
    b = log(1 / (float)p1680);
    ndli = (a - b) / (a + b);
    return ndli;
}

float cellulose_absorption_index(int p2000, int p2100, int p2200)
{
    float cai;
    cai = 0.5 * ((float)p2000 + (float)p2200) - (float)p2100;
    return cai;
}

float plant_senescence_reflectance_index(int p500, int p680, int p750)
{
    float psri;
    psri = ((float)p680 - (float)p500) / (float)p750;
    return psri;
}

float anthocyanin_reflectance_index_1(int p550, int p700)
{
    float ari1;
    ari1 = (1 / (float)p550) - (1 / (float)p700);
    return ari1;
}

float anthocyanin_reflectance_index_2(int p550, int p700, int p800)
{
    float ari2;
    ari2 = (float)p800 * ((1 / (float)p550) - (1 / (float)p700));
    return ari2;
}

float carotenoid_reflectance_index_1(int p510, int p550)
{
    float cri1;
    cri1 = (1 / (float)p510) - (1 / (float)p550);
    return cri1;
}

float carotenoid_reflectance_index_2(int p510, int p700)
{
    float cri2;
    cri2 = (1 / (float)p510) - (1 / (float)p700);
    return cri2;
}

float photochemical_reflectance_index(int p531, int p570)
{
    float pri;
    pri = ((float)p570 - (float)p531) / ((float)p570 + (float)p531);
    return pri;
}

float structure_insensitive_pigment_index(int p445, int p680, int p800)
{
    float sipi;
    sipi = ((float)p800 - (float)p445) / ((float)p800 + (float)p680);
    return sipi;
}