
#include "../include/SpectralIndices_math.h"
using namespace std;

// double转化为6位小数，并四舍五入
double transform_to_six_decimal_places(double x)
{
    double a, b;
    a = x * 1000000;
    b = round(a) / 1000000;
    return b;
}

int determine_band_range(double value_of_band, int value_of_needed_band)
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
int find_central_band(double *value_array_of_all_band, int size_of_all_band, int value_of_needed_band)
{
    int i, a;
    double j, k, x, y;
    int band_number = -1;
    double sub_value = 1000;
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
            j = x - (double)a;
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
double burn_area_index(int red, int nir)
{
    double a, b;
    double bai;
    a = pow(0.1 - (double)red, 2);
    b = pow(0.06 - (double)nir, 2);
    bai = 1 / (a + b);
    return bai;
}

double normalized_burn_ratio(int swir2, int nir)
{
    double a, b;
    double nbr;
    a = (double)nir - (double)swir2;
    b = (double)nir + (double)swir2;
    nbr = a / b;
    return nbr;
}

////////////////////////////////////////////////////////////////
// 没有thermal参数
double normalized_burn_ratio_thermal_1(int swir2, int nir, int thermal)
{
    double a, b;
    double nbrt1;
    a = (double)nir - (double)swir2 * ((double)thermal / 1000);
    b = (double)nir + (double)swir2 * ((double)thermal / 1000);
    nbrt1 = a / b;
    return nbrt1;
}
////////////////////////////////////////////////////////////////

// Geology Indices Background
double clay_minerals_ratio(int swir1, int swir2)
{
    double cmr;
    cmr = (double)swir1 / (double)swir2;
    return cmr;
}

double ferrous_minerals_ratio(int swir1, int nir)
{
    double fmr;
    fmr = (double)swir1 / (double)nir;
    return fmr;
}

double iron_oxide_ratio(int red, int blue)
{
    double ior;
    ior = (double)red / (double)blue;
    return ior;
}

double worldview_new_iron_index(int green, int yellow, int blue)
{
    double wvii;
    wvii = ((double)green - (double)yellow) / ((double)blue * 1000);
    return wvii;
}

double worldview_soil_index(int green, int yellow)
{
    double wvsi;
    wvsi = ((double)green - (double)yellow) / ((double)green + (double)yellow);
    return wvsi;
}

// Miscellaneous Indices Background
double modified_normalized_difference_water_index(int green, int swir1)
{
    double mndwi;
    mndwi = ((double)green - (double)swir1) / ((double)green + (double)swir1);
    return mndwi;
}

double normalized_difference_built_up_index(int swir1, int nir)
{
    double ndbi;
    ndbi = ((double)swir1 - (double)nir) / ((double)swir1 + (double)nir);
    return ndbi;
}

double normalized_difference_mud_index(int p795, int p990)
{
    double ndmi;
    ndmi = ((double)p795 - (double)p990) / ((double)p795 + (double)p990);
    return ndmi;
}

double normalized_difference_snow_index(int green, int nir)
{
    double ndsi;
    ndsi = ((double)green - (double)nir) / ((double)green + (double)nir);
    return ndsi;
}

double worldview_built_up_index(int coastal, int red_edge)
{
    double wvbi;
    wvbi = ((double)coastal - (double)red_edge) / ((double)coastal + (double)red_edge);
    return wvbi;
}

double worldView_non_homogeneous_feature_difference(int red_edge, int coastal)
{
    double wvnhfd;
    wvnhfd = ((double)red_edge - (double)coastal) / ((double)red_edge + (double)coastal);
    return wvnhfd;
}

double worldview_water_index(int coastal, int nir2)
{
    double wvwi;
    wvwi = ((double)coastal - (double)nir2) / ((double)coastal + (double)nir2);
    return wvwi;
}

// Vegetation Indices Background
double atmospherically_resistant_vegetation_index(int nir, int red, int blue)
{
    double arvi;
    double a, b;
    a = (double)nir - ((double)red - ((double)blue - (double)red));
    b = (double)nir + ((double)red - ((double)blue - (double)red));
    arvi = a / b;
    return arvi;
}

double difference_vegetation_index(int nir, int red)
{
    double dvi;
    dvi = (double)nir - (double)red;
    return dvi;
}

double enhanced_vegetation_index(int nir, int red, int blue)
{
    double evi;
    double a, b;
    a = 2.5 * ((double)nir - (double)red);
    b = (double)nir + 6 * (double)red - 7.5 * (double)blue + 1;
    evi = a / b;
    return evi;
}

double global_environmental_monitoring_index(int nir, int red)
{
    double gemi;
    double a, b, c;
    a = 2 * ((double)nir * (double)nir - (double)red * (double)red) + 1.5 * (double)nir + 0.5 * (double)red;
    b = (double)nir + (double)red + 0.5;
    c = a / b;
    a = (double)red - 0.125;
    b = 1 - (double)red;
    gemi = c * (1 - 0.25 * c) - (a / b);
    return gemi;
}

double green_atmospherically_resistant_index(int nir, int red, int green, int blue)
{
    double gari;
    double a, b;
    a = (double)nir - ((double)green - 1.7 * ((double)blue - (double)red));
    b = (double)nir + ((double)green - 1.7 * ((double)blue - (double)red));
    gari = a / b;
    return gari;
}

double green_difference_vegetation_index(int nir, int green)
{
    double gdvi;
    gdvi = (double)nir - (double)green;
    return gdvi;
}

double green_normalized_difference_vegetation_index(int nir, int green)
{
    double gndvi;
    double a, b;
    a = (double)nir - (double)green;
    b = (double)nir + (double)green;
    gndvi = a / b;
    return gndvi;
}

double green_ratio_vegetation_index(int nir, int green)
{
    double grvi;
    grvi = (double)nir / (double)green;
    return grvi;
}

// 没有TM卫星,暂时占位
double green_vegetation_index()
{
    return 0;
}

double infrared_percentage_vegetation_index(int nir, int red)
{
    double ipvi;
    ipvi = (double)nir / ((double)nir + (double)red);
    return ipvi;
}

double leaf_area_index(int nir, int red, int blue)
{
    double lai, evi;
    evi = enhanced_vegetation_index(nir, red, blue);
    lai = 3.618 * evi - 0.118;
    return lai;
}

double modified_non_linear_index(int nir, int red)
{
    double mnli, a, b;
    a = ((double)nir * (double)nir - (double)red) * 1.5;
    b = (double)nir * (double)nir + (double)red + 0.5;
    mnli = a / b;
    return mnli;
}

double modified_simple_ratio(int nir, int red)
{
    double msr, a, b, c;
    a = ((double)nir / (double)red) - 1;
    c = sqrt((double)nir / (double)red);
    b = c + 1;
    msr = a / b;
    return msr;
}

double non_linear_index(int nir, int red)
{
    double nli, a, b;
    a = (double)nir * (double)nir - (double)red;
    b = (double)nir * (double)nir + (double)red;
    nli = a / b;
    return nli;
}

double normalized_difference_vegetation_index(int nir, int red)
{
    double ndvi, a, b;
    a = (double)nir - (double)red;
    b = (double)nir + (double)red;
    ndvi = a / b;
    return ndvi;
}

double optimized_soil_adjusted_vegetation_index(int nir, int red)
{
    double osavi, a, b;
    a = 1.5 * ((double)nir - (double)red);
    b = (double)nir + (double)red + 0.16;
    osavi = a / b;
    return osavi;
}

double renormalized_difference_vegetation_index(int nir, int red)
{
    double rdvi, a, b, c;
    a = (double)nir - (double)red;
    c = (double)nir + (double)red;
    b = sqrt(c);
    rdvi = a / b;
    return rdvi;
}

double soil_adjusted_vegetation_index(int nir, int red)
{
    double savi, a, b;
    a = 1.5 * ((double)nir - (double)red);
    b = (double)nir + (double)red + 0.5;
    savi = a / b;
    return savi;
}

double simple_ratio(int nir, int red)
{
    double sr;
    sr = (double)nir / (double)red;
    return sr;
}

double Transformed_difference_vegetation_index(int nir, int red)
{
    double tdvi, a, b;
    a = ((double)nir - (double)red) / ((double)nir + (double)red);
    b = a + 0.5;
    tdvi = sqrt(b);
    return tdvi;
}

double visible_atmospherically_resistant_index(int red, int green, int blue)
{
    double vari;
    vari = ((double)green - (double)red) / ((double)green + (double)red - (double)blue);
    return vari;
}

double worldview_improved_vegetative_index(int nir2, int red)
{
    double wvvi;
    wvvi = ((double)nir2 - (double)red) / ((double)nir2 + (double)red);
    return wvvi;
}

double modified_chlorophyll_absorption_ratio_index(int p550, int p670, int p700)
{
    double mcari;
    mcari = (((double)p700 - (double)p670) - 0.2 * ((double)p700 - (double)p550)) * ((double)p700 / (double)p670);
    return mcari;
}

double modified_chlorophyll_absorption_ratio_index_improved(int p550, int p670, int p800)
{
    double mcari2, a, b, c, d;
    a = 1.5 * (2.5 * ((double)p800 - (double)p670) - 1.3 * ((double)p800 - (double)p550));
    d = sqrt((double)p670);
    c = (2 * (double)p800 + 1) * (2 * (double)p800 + 1) - (6 * (double)p800 - 5 * d) - 0.5;
    b = sqrt(c);
    mcari2 = a / b;
    return mcari2;
}

double modified_red_edge_normalized_difference_vegetation_index(int p445, int p705, int p750)
{
    double mrendvi, a, b;
    a = (double)p750 - (double)p705;
    b = (double)p750 + (double)p705 - 2 * (double)p445;
    mrendvi = a / b;
    return mrendvi;
}

double modified_red_edge_simple_ratio(int p445, int p705, int p750)
{
    double mresr;
    mresr = ((double)p750 - (double)p445) / ((double)p705 - (double)p445);
    return mresr;
}

double modified_triangular_vegetation_index(int p550, int p670, int p800)
{
    double mtvi;
    mtvi = 1.2 * (1.2 * ((double)p800 - (double)p550) - 2.5 * ((double)p670 - (double)p550));
    return mtvi;
}

double modified_triangular_vegetation_index_improved(int p550, int p670, int p800)
{
    double mtvi2, a, b, c, d;
    a = 1.5 * (1.2 * ((double)p800 - (double)p550) - 2.5 * ((double)p670 - (double)p550));
    c = sqrt((double)p670);
    d = (2 * (double)p800 + 1) * (2 * (double)p800 + 1) - (6 * (double)p800 - 5 * c) - 0.5;
    b = sqrt(d);
    mtvi2 = a / b;
    return mtvi2;
}

double red_edge_normalized_difference_vegetation_index(int p705, int p750)
{
    double rendvi;
    rendvi = ((double)p750 - (double)p705) / ((double)p750 + (double)p705);
    return rendvi;
}

// 690 nm至740 nm光谱中植被红边区域反射率最大导数的波长,暂时未实现，占位
double red_edge_position_index()
{
    return 0;
}

double transformed_chlorophyll_absorption_reflectance_index(int p550, int p670, int p700)
{
    double tcari;
    tcari = 3 * (((double)p700 - (double)p670) - 0.2 * ((double)p700 - (double)p550) * ((double)p700 / (double)p670));
    return tcari;
}

double triangular_vegetation_index(int p550, int p670, int p750)
{
    double tvi;
    tvi = 0.5 * (120 * ((double)p750 - (double)p550) - 200 * ((double)p670 - (double)p550));
    return tvi;
}

double vogelmann_red_edge_index_1(int p720, int p740)
{
    double vrei1;
    vrei1 = (double)p740 / (double)p720;
    return vrei1;
}

double vogelmann_red_edge_index_2(int p715, int p726, int p734, int p747)
{
    double vrei2;
    vrei2 = ((double)p734 - (double)p747) / ((double)p715 - (double)p726);
    return vrei2;
}

double normalized_difference_nitrogen_index(int p1510, int p1680)
{
    double ndni, a, b;
    a = log(1 / (double)p1510);
    b = log(1 / (double)p1680);
    ndni = (a - b) / (a + b);
    return ndni;
}

double moisture_stress_index(int p1599, int p819)
{
    double msi;
    msi = (double)p1599 / (double)p819;
    return msi;
}

double normalized_difference_infrared_index(int p819, int p1649)
{
    double ndii;
    ndii = ((double)p819 - (double)p1649) / ((double)p819 + (double)p1649);
    return ndii;
}

double normalized_difference_water_index(int p857, int p1241)
{
    double ndwi;
    ndwi = ((double)p857 - (double)p1241) / ((double)p857 + (double)p1241);
    return ndwi;
}

double normalized_multi_band_drought_index(int p860, int p1640, int p2130)
{
    double ndmi, a, b;
    a = (double)p860 - ((double)p1640 - (double)p2130);
    b = (double)p860 + ((double)p1640 - (double)p2130);
    ndmi = a / b;
    return ndmi;
}

double water_band_index(int p900, int p970)
{
    double wbi;
    wbi = (double)p970 / (double)p900;
    return wbi;
}

double normalized_difference_lignin_index(int p1680, int p1754)
{
    double ndli, a, b;
    a = log(1 / (double)p1754);
    b = log(1 / (double)p1680);
    ndli = (a - b) / (a + b);
    return ndli;
}

double cellulose_absorption_index(int p2000, int p2100, int p2200)
{
    double cai;
    cai = 0.5 * ((double)p2000 + (double)p2200) - (double)p2100;
    return cai;
}

double plant_senescence_reflectance_index(int p500, int p680, int p750)
{
    double psri;
    psri = ((double)p680 - (double)p500) / (double)p750;
    return psri;
}

double anthocyanin_reflectance_index_1(int p550, int p700)
{
    double ari1;
    ari1 = (1 / (double)p550) - (1 / (double)p700);
    return ari1;
}

double anthocyanin_reflectance_index_2(int p550, int p700, int p800)
{
    double ari2;
    ari2 = (double)p800 * ((1 / (double)p550) - (1 / (double)p700));
    return ari2;
}

double carotenoid_reflectance_index_1(int p510, int p550)
{
    double cri1;
    cri1 = (1 / (double)p510) - (1 / (double)p550);
    return cri1;
}

double carotenoid_reflectance_index_2(int p510, int p700)
{
    double cri2;
    cri2 = (1 / (double)p510) - (1 / (double)p700);
    return cri2;
}

double photochemical_reflectance_index(int p531, int p570)
{
    double pri;
    pri = ((double)p570 - (double)p531) / ((double)p570 + (double)p531);
    return pri;
}

double structure_insensitive_pigment_index(int p445, int p680, int p800)
{
    double sipi;
    sipi = ((double)p800 - (double)p445) / ((double)p800 + (double)p680);
    return sipi;
}
