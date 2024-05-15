
#include <iostream>
#include <cmath>
using namespace std;

//光谱指数名称缩写索引
enum SpectralIndices
{
    BAI,
    NBR,
    NBRT1,
    CMR,
    FMR,
    IOR,
    WV_II,
    WV_SI,
    MNDWI,
    NDBI,
    NDMI,
    NDSI,
    WV_BI,
    WV_NHFD,
    WV_WI,
    ARVI,
    DVI,
    EVI,
    GEMI,
    GARI,
    GDVI,
    GNDVI,
    GRVI,
    GVI,
    IPVI,
    LAI,
    MNLI,
    MSR,
    NLI,
    NDVI,
    OSAVI,
    RDVI,
    SAVI,
    SR,
    SGI,
    TDVI,
    VARI,
    WV_VI,
    MCARI,
    MCARI2,
    MRENDVI,
    MRESR,
    MTVI,
    MTVI2,
    RENDVI,
    REPI,
    TCARI,
    TVI,
    VREI1,
    VREI2,
    NDNI,
    MSI,
    NDII,
    NDWI,
    NMDI,
    WBI,
    NDLI,
    CAI,
    PSRI,
    ARI1,
    ARI2,
    CRI1,
    CRI2,
    PRI,
    SIPI,
    RGRI
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
float atmospherically_resistant_vegetation_index(int nir, int red, int blue);
float difference_vegetation_index(int nir,int red);
float enhanced_vegetation_index(int nir,int red,int blue);
float global_environmental_monitoring_index(int nir,int red);
float green_atmospherically_resistant_index(int nir,int red,int green,int blue);
float green_difference_vegetation_index(int nir,int green);
float green_normalized_difference_vegetation_index(int nir,int green);
float green_ratio_vegetation_index(int nir,int green);
float green_vegetation_index();
float infrared_percentage_vegetation_index(int nir, int red);
float leaf_area_index(int nir,int red,int blue);
float modified_non_linear_index(int nir,int red);
float modified_simple_ratio(int nir,int red);
float non_linear_index(int nir,int red);
float normalized_difference_vegetation_index(int nir,int red);
float optimized_soil_adjusted_vegetation_index(int nir,int red);
float renormalized_difference_vegetation_index(int nir,int red);
float soil_adjusted_vegetation_index(int nir,int red);
float simple_ratio(int nir,int red);
float sum_green_index(void);
float Transformed_difference_vegetation_index(int nir, int red);
float visible_atmospherically_resistant_index(int red,int green,int blue);
float modified_chlorophyll_absorption_ratio_index(int p550,int p670,int p700);
float modified_chlorophyll_absorption_ratio_index_improved(int p550,int p670,int p800);
float modified_red_edge_normalized_difference_vegetation_index(int p445,int p705,int p750);
float modified_red_edge_simple_ratio(int p445,int p705,int p750);
float modified_triangular_vegetation_index(int p550,int p670,int p800);
float modified_triangular_vegetation_index_improved(int p550,int p670,int p800);
float red_edge_normalized_difference_vegetation_index(int p705,int p750);
float transformed_chlorophyll_absorption_reflectance_index(int p550,int p670,int p700);
float triangular_vegetation_index(int p550,int p670,int p750);
float vogelmann_red_edge_index_1(int p720,int p740);
float vogelmann_red_edge_index_2(int p715,int p726,int p734,int p747);
float normalized_difference_nitrogen_index(int p1510,int p1680);
float moisture_stress_index(int p1599,int p819);
float normalized_difference_infrared_index(int p819,int p1649);
float normalized_difference_water_index(int p857,int p1241);
float normalized_multi_band_drought_index(int p860,int p1640,int p2130);
float water_band_index(int p900,int p970);
float normalized_difference_lignin_index(int p1680 ,int p1754);
float cellulose_absorption_index(int p2000,int p2100,int p2200);
float plant_senescence_reflectance_index(int p500,int p680,int p750);
float anthocyanin_reflectance_index_1(int p550,int p700);
float anthocyanin_reflectance_index_2(int p550,int p700,int p800);
float carotenoid_reflectance_index_1(int p510,int p550);
float carotenoid_reflectance_index_2(int p510,int p700);
float photochemical_reflectance_index(int p531,int p570);
float structure_insensitive_pigment_index(int p445,int p680,int p800);
float red_green_ratio_index();