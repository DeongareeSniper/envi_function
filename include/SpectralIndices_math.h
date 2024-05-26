
#include <iostream>
#include <cmath>
using namespace std;

// 为避免在判断中与窄频段冲突，下列波长为该频段中心波长（nm）加1
#define BLUE 471
#define GREEN 551
#define RED 651
#define NIR 861
#define SWIR1 1651
#define SWIR2 2221
#define p715_wide 716
#define p750_narrow 751
#define p800_wide 801

// 说明文档里没有，无法确定中心波长，下列数据为根据网上资料猜测，以下参数用于wvbi,wvnhfd,wvwi,wvii,wvsi,nbrt1
#define Coastal 425
#define YELLOW 605
#define Red_Edge 725
#define NIR2 950
#define Thermal 1150

// 光谱指数名称缩写索引
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

double transform_to_six_decimal_places(double x);
int determine_band_range(double value_of_band, int value_of_needed_band);
int find_central_band(double *value_array_of_all_band, int size_of_all_band, int value_of_needed_band);

// 光谱指数计算公式函数声明
double burn_area_index(int red, int nir);
double normalized_burn_ratio(int swir, int nir);
double normalized_burn_ratio_thermal_1(int swir, int nir, int thermal);
double clay_minerals_ratio(int swir1, int swir2);
double ferrous_minerals_ratio(int swir, int nir);
double iron_oxide_ratio(int red, int blue);
double worldview_new_iron_index(int green, int yellow, int blue);
double worldview_soil_index(int green, int yellow);
double modified_normalized_difference_water_index(int green, int swir);
double normalized_difference_built_up_index(int swir, int nir);
double normalized_difference_mud_index(int p795, int p990);
double normalized_difference_snow_index(int green, int nir);
double worldview_built_up_index(int coastal, int red_edge);
double worldView_non_homogeneous_feature_difference(int red_edge, int coastal);
double worldview_water_index(int coastal, int nir2);
double atmospherically_resistant_vegetation_index(int nir, int red, int blue);
double difference_vegetation_index(int nir, int red);
double enhanced_vegetation_index(int nir, int red, int blue);
double global_environmental_monitoring_index(int nir, int red);
double green_atmospherically_resistant_index(int nir, int red, int green, int blue);
double green_difference_vegetation_index(int nir, int green);
double green_normalized_difference_vegetation_index(int nir, int green);
double green_ratio_vegetation_index(int nir, int green);
////////////////////////////////
double green_vegetation_index();
////////////////////////////////
double infrared_percentage_vegetation_index(int nir, int red);
double leaf_area_index(int nir, int red, int blue);
double modified_non_linear_index(int nir, int red);
double modified_simple_ratio(int nir, int red);
double non_linear_index(int nir, int red);
double normalized_difference_vegetation_index(int nir, int red);
double optimized_soil_adjusted_vegetation_index(int nir, int red);
double renormalized_difference_vegetation_index(int nir, int red);
double soil_adjusted_vegetation_index(int nir, int red);
double simple_ratio(int nir, int red);
double Transformed_difference_vegetation_index(int nir, int red);
double visible_atmospherically_resistant_index(int red, int green, int blue);
double worldview_improved_vegetative_index(int nir2, int red);
double modified_chlorophyll_absorption_ratio_index(int p550, int p670, int p700);
double modified_chlorophyll_absorption_ratio_index_improved(int p550, int p670, int p800);
double modified_red_edge_normalized_difference_vegetation_index(int p445, int p705, int p750);
double modified_red_edge_simple_ratio(int p445, int p705, int p750);
double modified_triangular_vegetation_index(int p550, int p670, int p800);
double modified_triangular_vegetation_index_improved(int p550, int p670, int p800);
double red_edge_normalized_difference_vegetation_index(int p705, int p750);
//----------------------------------------------------------------
double red_edge_position_index();
//----------------------------------------------------------------
double transformed_chlorophyll_absorption_reflectance_index(int p550, int p670, int p700);
double triangular_vegetation_index(int p550, int p670, int p750);
double vogelmann_red_edge_index_1(int p720, int p740);
double vogelmann_red_edge_index_2(int p715, int p726, int p734, int p747);
double normalized_difference_nitrogen_index(int p1510, int p1680);
double moisture_stress_index(int p1599, int p819);
double normalized_difference_infrared_index(int p819, int p1649);
double normalized_difference_water_index(int p857, int p1241);
double normalized_multi_band_drought_index(int p860, int p1640, int p2130);
double water_band_index(int p900, int p970);
double normalized_difference_lignin_index(int p1680, int p1754);
double cellulose_absorption_index(int p2000, int p2100, int p2200);
double plant_senescence_reflectance_index(int p500, int p680, int p750);
double anthocyanin_reflectance_index_1(int p550, int p700);
double anthocyanin_reflectance_index_2(int p550, int p700, int p800);
double carotenoid_reflectance_index_1(int p510, int p550);
double carotenoid_reflectance_index_2(int p510, int p700);
double photochemical_reflectance_index(int p531, int p570);
double structure_insensitive_pigment_index(int p445, int p680, int p800);
