/*
作者：邱子粤
Email：782381967@qq.com
主题：ENVI光谱函数库
时间：2024-01-15

备注：传入参数单位均为
*/

#include <iostream>
#include <cmath>
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

float normalized_burn_ratio(float swir, float nir)
{
    float a, b;
    float nbr;
    a = nir - swir;
    b = nir + swir;
    nbr = a / b;
    return nbr;
}

float normalized_burn_ratio_thermal_1(float swir, float nir, float thermal)
{
    float a, b;
    float nbrt1;
    a = nir - swir * (thermal / 1000);
    b = nir + swir * (thermal / 1000);
    nbrt1 = a / b;
    return nbrt1;
}

// Geology Indices Background
float clay_minerals_ratio(float swir1, float swir2)
{
    float cmr;
    cmr = swir1 / swir2;
    return cmr;
}

float ferrous_minerals_ratio(float swir, float nir)
{
    float fmr;
    fmr = swir / nir;
    return fmr;
}

float iron_oxide_ratio(float red, float blue)
{
    float ior;
    ior = red / blue;
    return ior;
}

float worldview_new_iron_index(float green, float yellow, float blue)
{
    float wvii;
    wvii = (green - yellow) / (blue * 1000);
    cout << "WV-II is " << wvii << endl;
    return wvii;
}

float worldview_soil_index(float green, float yellow)
{
    float wvsi;
    wvsi = (green - yellow) / (green + yellow);
    return wvsi;
}

// Miscellaneous Indices Background
float modified_normalized_difference_water_index(float green, float swir)
{
    float mndwi;
    mndwi = (green - swir) / (green + swir);
    return mndwi;
}

float normalized_difference_built_up_index(float swir, float nir)
{
    float ndbi;
    ndbi = (swir - nir) / (swir + nir);
    return ndbi;
}

float normalized_difference_mud_index(float p795, float p990)
{
    float ndmi;
    ndmi = (p795 - p990) / (p795 + p990);
    return ndmi;
}

float normalized_difference_snow_index(float green, float nir)
{
    float ndsi;
    ndsi = (green - nir) / (green + nir);
    return ndsi;
}

float worldview_built_up_index(float coastal, float red_edge)
{
    float wvbi;
    wvbi = (coastal - red_edge) / (coastal + red_edge);
    return wvbi;
}

float worldView_non_homogeneous_feature_difference(float red_edge, float coastal)
{
    float wvnhfd;
    wvnhfd = (red_edge - coastal) / (red_edge + coastal);
    return wvnhfd;
}

float worldview_water_index(float coastal, float nir2)
{
    float wvwi;
    wvwi = (coastal - nir2) / (coastal + nir2);
    return wvwi;
}

inline float transform_to_six_decimal_places(float x)
{
    float a,c;
    int b;
    a = x*1000000;
    b=(int)a;
    c = (float)b/1000000;
    return c;
}

//testing
int main(int argc, const char **argv)
{
    int green, yellow, blue;
    green = 657;
    yellow = 499;
    blue = 124;
    float wvii = transform_to_six_decimal_places(worldview_new_iron_index(green, yellow, blue));
    std::cout << "WV_II is " << wvii << std::endl;
    return 0;
}
