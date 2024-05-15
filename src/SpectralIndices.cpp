
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

////////////////////////////////////////////////////////////////
//没有thermal参数
float normalized_burn_ratio_thermal_1(int swir, int nir, int thermal)
{
    float a, b;
    float nbrt1;
    a = (float)nir - (float)swir * ((float)thermal / 1000);
    b = (float)nir + (float)swir * ((float)thermal / 1000);
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

//Vegetation Indices Background
float atmospherically_resistant_vegetation_index(int nir, int red, int blue)
{
    float arvi;
    float a,b;
    a=(float)nir-((float)red-((float)blue-(float)red));
    b=(float)nir+((float)red-((float)blue-(float)red));
    arvi = a/b;
    return arvi;
}

float difference_vegetation_index(int nir,int red)
{
    float dvi;
    dvi = (float)nir-(float)red;
    return dvi;
}
////////////////////////////////////////////////////////////////////////
float enhanced_vegetation_index(int nir,int red,int blue)
{
    float evi;
    float a,b;
    a=2.5*(nir-red);
    b=nir+6*red-7.5*blue+1;
    evi=a/b;
    return evi;
}

float global_environmental_monitoring_index(int nir,int red)
{
    float gemi;
    float a,b,c;
    a=2*(nir*nir-red*red)+1.5*nir+0.5*red;
    b=nir+red+0.5;
    c=a/b;
    a=red-0.125;
    b=1-red;
    gemi=c*(1-0.25*c)-(a/b);
    return gemi;
} 

float green_atmospherically_resistant_index(int nir,int red,int green,int blue)
{
    float gari;
    float a,b;
    a=nir-(green-1.7*(blue-red));
    b=nir+(green-1.7*(blue-red));
    gari=a/b;
    return gari;
}

float green_difference_vegetation_index(int nir,int green)
{
    float gdvi;
    gdvi=nir-green;
    return gdvi;
}

float green_normalized_difference_vegetation_index(int nir,int green)
{
    float gndvi;
    float a,b;
    a=nir-green;
    b=nir+green;
    gndvi=a/b;
    return gndvi;
}

float green_ratio_vegetation_index(int nir,int green)
{
    float grvi;
    grvi=nir/green;
    return grvi;
}

//没有TM卫星,暂时占位
float green_vegetation_index()
{
    return 0;
}

float infrared_percentage_vegetation_index(int nir, int red)
{
    float ipvi;
    ipvi=nir/(nir+red);
    return ipvi;
}

float leaf_area_index(int nir,int red,int blue)
{
    float lai,evi;
    evi=enhanced_vegetation_index(nir,red,blue);
    lai=3.618*evi-0.118;
    return lai;
}

float modified_non_linear_index(int nir,int red)
{
    float mnli,a,b;
    a=(nir*nir-red)*1.5;
    b=nir*nir+red+0.5;
    mnli=a/b;
    return mnli;
}

float modified_simple_ratio(int nir,int red)
{
    float msr,a,b,c;
    a=(nir/red)-1;
    c=sqrt(nir/red);
    b=c+1;
    msr=a/b;
    return msr;
}

float non_linear_index(int nir,int red)
{
    float nli,a,b;
    a=nir*nir-red;
    b=nir*nir+red;
    nli=a/b;
    return nli;
}

float normalized_difference_vegetation_index(int nir,int red)
{
    float ndvi,a,b;
    a=nir-red;
    b=nir+red;
    ndvi+a/b;
    return ndvi;
}

float optimized_soil_adjusted_vegetation_index(int nir,int red)
{
    float osavi,a,b;
    a=1.5*(nir-red);
    b=nir+red+0.16;
    osavi=a/b;
    return osavi;
}

float renormalized_difference_vegetation_index(int nir,int red)
{
    float rdvi,a,b,c;
    a=nir-red;
    c=nir+red;
    b=sqrt(c);
    rdvi=a/b;
    return rdvi;
}

float soil_adjusted_vegetation_index(int nir,int red)
{
    float savi,a,b;
    a=1.5*(nir-red);
    b=nir+red+0.5;
    savi=a/b;
    return savi;
}

float simple_ratio(int nir,int red)
{
    float sr;
    sr=nir/red;
    return sr;
}

//此指数计算方法为500到600nm波段求平均值，此为暂时占位
float sum_green_index(void)
{
    return 0;
}

float Transformed_difference_vegetation_index(int nir, int red)
{
    float tdvi,a,b;
    a=(nir-red)/(nir+red);
    b=a+0.5;
    tdvi=sqrt(b);
    return tdvi;
}

float visible_atmospherically_resistant_index(int red,int green,int blue)
{
    float vari;
    vari = (green-red)/(green+red-blue);
    return vari;
}

float worldview_improved_vegetative_index(int nir2,int red)
{
    float wvvi;
    wvvi= (nir2-red)/(nir2+red);
    return wvvi;
}

float modified_chlorophyll_absorption_ratio_index(int p550,int p670,int p700)
{
    float mcari;
    mcari=((p700-p670)-0.2*(p700-p550))*(p700/p670);
    return mcari;
}

float modified_chlorophyll_absorption_ratio_index_improved(int p550,int p670,int p800)
{
    float mcari2,a,b,c,d;
    a=1.5*(2.5*(p800-p670)-1.3*(p800-p550));
    d=sqrt(p670);
    c=(2*p800+1)*(2*p800+1)-(6*p800-5*d)-0.5;
    b=sqrt(c);
    mcari2=a/b;
    return mcari2;
}

float modified_red_edge_normalized_difference_vegetation_index(int p445,int p705,int p750)
{
    float mrendvi,a,b;
    a=p750-p705;
    b=p750+p705-2*p445;
    mrendvi=a/b;
    return mrendvi;
}

float modified_red_edge_simple_ratio(int p445,int p705,int p750)
{
    float mresr;
    mresr = (p750-p445)/(p705-p445);
    return mresr;
}

float modified_triangular_vegetation_index(int p550,int p670,int p800)
{
    float mtvi;
    mtvi = 1.2*(1.2*(p800-p550)-2.5*(p670-p550));
    return mtvi;
}

float modified_triangular_vegetation_index_improved(int p550,int p670,int p800)
{
    float mtvi2,a,b,c,d;
    a=1.5*(1.2*(p800-p550)-2.5*(p670-p550));
    c=sqrt(p670);
    d=(2*p800+1)*(2*p800+1)-(6*p800-5*c)-0.5;
    b=sqrt(d);
    mtvi2 = a/b;
    return mtvi2;
}

float red_edge_normalized_difference_vegetation_index(int p705,int p750)
{
    float rendvi;
    rendvi =(p750-p705)/(p750+p705);
    return rendvi;
}

//690 nm至740 nm光谱中植被红边区域反射率最大导数的波长,暂时未实现，占位
float red_edge_position_index()
{
    return 0;
}

float transformed_chlorophyll_absorption_reflectance_index(int p550,int p670,int p700)
{
    float tcari;
    tcari=3*((p700-p670)-0.2*(p700-p550)*(p700/p670));
    return tcari;
}

float triangular_vegetation_index(int p550,int p670,int p750)
{
    float tvi;
    tvi= 0.5*(120*(p750-p550)-200*(p670-p550));
    return tvi;
}

float vogelmann_red_edge_index_1(int p720,int p740)
{
    float vrei1;
    vrei1=p740/p720;
    return vrei1;
}

float vogelmann_red_edge_index_2(int p715,int p726,int p734,int p747)
{
    float vrei2;
    vrei2 = (p734-p747)/(p715-p726);
    return vrei2;
}

float normalized_difference_nitrogen_index(int p1510,int p1680)
{
    float ndni,a,b;
    a=log(1/p1510);
    b=log(1/p1680);
    ndni=(a-b)/(a+b);
    return ndni;
}

float moisture_stress_index(int p1599,int p819)
{
    float msi;
    msi=p1599/p819;
    return msi;
}

float normalized_difference_infrared_index(int p819,int p1649)
{
    float ndii;
    ndii=(p819-p1649)/(p819+p1649);
    return ndii;
}

float normalized_difference_water_index(int p857,int p1241)
{
    float ndwi;
    ndwi = (p857-p1241)/(p857+p1241);
    return ndwi;
}

float normalized_multi_band_drought_index(int p860,int p1640,int p2130)
{
    float ndmi,a,b;
    a=p860-(p1640-p2130);
    b=p860+(p1640-p2130);
    ndmi=a/b;
    return ndmi;
}

float water_band_index(int p900,int p970)
{
    float wbi;
    wbi=p970/p900;
    return wbi;
}

float normalized_difference_lignin_index(int p1680 ,int p1754)
{
    float ndli,a,b;
    a=log(1/p1754);
    b=log(1/p1680);
    ndli=(a-b)/(a+b);
    return ndli;
}

float cellulose_absorption_index(int p2000,int p2100,int p2200)
{
    float cai;
    cai=0.5*(p2000+p2200)-p2100;
    return cai;
}

float plant_senescence_reflectance_index(int p500,int p680,int p750)
{
    float psri;
    psri=(p680-p500)/p750;
    return psri;
}

float anthocyanin_reflectance_index_1(int p550,int p700)
{
    float ari1;
    ari1 = (1/p550)-(1/p700);
    return ari1;
}

float anthocyanin_reflectance_index_2(int p550,int p700,int p800)
{
    float ari2;
    ari2 = p800*((1/p550)-(1/p700));
    return ari2;
} 

float carotenoid_reflectance_index_1(int p510,int p550)
{
    float cri1;
    cri1=(1/p510)-(1/p550);
    return cri1;
}

float carotenoid_reflectance_index_2(int p510,int p700)
{
    float cri2;
    cri2=(1/p510)-(1/p700);
    return cri2;
}

float photochemical_reflectance_index(int p531,int p570)
{
    float pri;
    pri=(p570-p531)/(p570+p531);
    return pri;
}

float structure_insensitive_pigment_index(int p445,int p680,int p800)
{
    float sipi;
    sipi=(p800-p445)/(p800+p680);
    return sipi;
}

//红色范围内所有波段的平均值除以绿色范围内所有频段的平均值。暂时占位
float red_green_ratio_index()
{
    return 0;
}