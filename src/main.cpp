/*
作者：邱子粤
Email：782381967@qq.com
主题：ENVI光谱函数库
时间：2024-01-15

备注：传入参数单位均为微米（um）
*/

#include <iostream>
#include <cmath>

// Burn Indices Background
float burn_area_index(float red, float nir)
{
    float a, b;
    float bai;
    a = pow(0.1 - red, 2);
    b = pow(0.06 - nir, 2);
    bai = 1 / (a + b);
    std::cout << "BAI is" << bai << "%" << std::endl;
    return bai;
    // std::cout << "Hello, from envi_function!\n";
}

float normalized_burn_ratio(float swir, float nir)
{
    float a, b;
    float nbr;
    a = nir - swir;
    b = nir + swir;
    nbr = a / b;
    std::cout << "NBR is" << nbr << "%" << std::endl;
    return nbr;
}

float normalized_burn_ratio_thermal_1(float swir, float nir, float thermal)
{
    float a, b;
    float nbrt1;
    a = nir - swir * (thermal / 1000);
    b = nir + swir * (thermal / 1000);
    nbrt1 = a / b;
    std::cout << "NBRT1 is" << nbrt1 << "%" << std::endl;
    return nbrt1;
}

// Geology Indices Background
float clay_minerals_ratio(float swir1, float swir2)
{
    float cmr;
    cmr = swir1 / swir2;
    std::cout << "CMR is" << cmr << "%" << std::endl;
    return cmr;
}

float ferrous_minerals_ratio(float swir, float nir)
{
    float fmr;
    fmr = swir / nir;
    std::cout << "FMR is" << fmr << "%" << std::endl;
    return fmr;
}

float iron_oxide_ratio(float red, float blue)
{
    float ixr;
    ixr = red / blue;
    std::cout << "IXR is" << ixr << "%" << std::endl;
    return ixr;
}

float worldview_new_iron_index(float green, float yellow, float blue)
{
    float wvii;
    wvii = (green - yellow) / (blue * 1000);
    std::cout << "WV-II is" << wvii << "%" << std::endl;
    return wvii;
}

float worldview_soil_index(float green, float yellow)
{
    float wvsi;
    wvsi = (green - yellow) / (green + yellow);
    std::cout << "WV-SI is" << wvsi << "%" << std::endl;
    return wvsi;
}

// Miscellaneous Indices Background
float modified_normalized_difference_water_index(float green, float swir)
{
    float mndwi;
    mndwi = (green - swir) / (green + swir);
    std::cout << "MNDWI is" << mndwi << "%" << std::endl;
    return mndwi;
}

float normalized_difference_built_up_index(float swir, float nir)
{
    float ndbi;
    ndbi = (swir - nir) / (swir + nir);
    std::cout << "NDBI is" << ndbi << "%" << std::endl;
    return ndbi;
}

float normalized_difference_mud_index(float p795, float p990)
{
    float ndmi;
    ndmi = (p795 - p990) / (p795 + p990);
    std::cout << "NDMI is" << ndmi << "%" << std::endl;
    return ndmi;
}

float normalized_difference_snow_index(float green, float nir)
{
    float ndsi;
    ndsi = (green - nir) / (green + nir);
    std::cout << "NDSI is" << ndsi << "%" << std::endl;
    return ndsi;
}

float worldview_built_up_index(float coastal, float red_edge)
{
    float wvbi;
    wvbi = (coastal - red_edge) / (coastal + red_edge);
    std::cout << "WV-BUI is" << wvbi << "%" << std::endl;
    return wvbi;
}

float worldView_non_homogeneous_feature_difference(float red_edge, float coastal)
{
    float wvnhfd;
    wvnhfd = (red_edge - coastal) / (red_edge + coastal);
    std::cout << "WV-NHFD is" << wvnhfd << "%" << std::endl;
    return wvnhfd;
}

float worldview_water_index(float coastal, float nir2)
{
    float wvwi;
    wvwi = (coastal - nir2) / (coastal + nir2);
    std::cout << "WV-WI is" << wvwi << "%" << std::endl;
    return wvwi;
}

int main(int argc, const char **argv)
{
    int red, nir;
    red = 0.6;
    nir = 0.76;
    float bai = burn_area_index(red, nir);
    std::cout << "BAI is" << bai << "%" << std::endl;
    return 0;
}
