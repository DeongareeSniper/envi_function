
#include <iostream>
#include <cmath>
using namespace std;

//光谱指数名称缩写索引
enum SpectralIndices
{
    bai,
    nbr,
    nbrt1,
    cmr,
    fmr,
    ior,
    wvii,
    wvsi,
    mndwi,
    ndbi,
    ndmi,
    ndsi,
    wvbi,
    wvnhfd,
    wvwi
};

//光谱指数计算公式函数声明
float burn_area_index(int red, int nir);
float normalized_burn_ratio(int swir, int nir);
float normalized_burn_ratio_thermal_1(int swir, int nir, int thermal);
float clay_minerals_ratio(int swir1, int swir2);
float ferrous_minerals_ratio(int swir, int nir);
float iron_oxide_ratio(int red, int blue);
float worldview_new_iron_index(int green, int yellow, int blue);
float worldview_soil_index(int green, int yellow);
float modified_normalized_difference_water_index(int green, int swir);
float normalized_difference_built_up_index(int swir, int nir);
float normalized_difference_mud_index(int p795, int p990);
float normalized_difference_snow_index(int green, int nir);
float worldview_built_up_index(int coastal, int red_edge);
float worldView_non_homogeneous_feature_difference(int red_edge, int coastal);
float worldview_water_index(int coastal, int nir2);
