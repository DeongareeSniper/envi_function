
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
    a = (float)nir - (float)swir;
    b = (float)nir + (float)swir;
    nbr = a / b;
    return nbr;
}

// float normalized_burn_ratio_thermal_1(int swir, int nir, int thermal)
// {
//     float a, b;
//     float nbrt1;
//     a = (float)nir - (float)swir * ((float)thermal / 1000);
//     b = (float)nir + (float)swir * ((float)thermal / 1000);
//     nbrt1 = a / b;
//     return nbrt1;
// }

// Geology Indices Background
float clay_minerals_ratio(int swir1, int swir2)
{
    float cmr;
    cmr = (float)swir1 / (float)swir2;
    return cmr;
}

float ferrous_minerals_ratio(int swir, int nir)
{
    float fmr;
    fmr = (float)swir / (float)nir;
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
float modified_normalized_difference_water_index(int green, int swir)
{
    float mndwi;
    mndwi = ((float)green - (float)swir) / ((float)green + (float)swir);
    return mndwi;
}

float normalized_difference_built_up_index(int swir, int nir)
{
    float ndbi;
    ndbi = ((float)swir - (float)nir) / ((float)swir + (float)nir);
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