/*
作者：邱子粤
Email：782381967@qq.com
主题：ENVI光谱函数库
时间：2024-01-15
*/

#include "../include/SpectralIndices.h"
using namespace std;

// 光谱指数计算模块对外接口
int spectral_index_calculation(int ***raw_data, int x, int y, int z, float *value_array_of_all_band,
                               SpectralIndices spectralindices_index, float **result)
{
    switch (spectralindices_index)
    {
    case BAI:
        bai(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NBR:
        nbr(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NBRT1:
        nbrt1(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case CMR:
        cmr(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case FMR:
        fmr(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case IOR:
        ior(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WV_II:
        wv_ii(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WV_SI:
        wv_si(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MNDWI:
        mndwi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDBI:
        ndbi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDMI:
        ndmi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDSI:
        ndsi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WV_BI:
        wv_bi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WV_NHFD:
        wv_nhfd(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WV_WI:
        wv_wi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case ARVI:
        arvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case DVI:
        dvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case EVI:
        evi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case GEMI:
        gemi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case GARI:
        gari(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case GDVI:
        gdvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case GNDVI:
        gndvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case GRVI:
        grvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case GVI:
        gvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case IPVI:
        ipvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case LAI:
        lai(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MNLI:
        mnli(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MSR:
        msr(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NLI:
        nli(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDVI:
        ndvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case OSAVI:
        osavi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case RDVI:
        rdvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case SAVI:
        savi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case SR:
        sr(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case SGI:
        sgi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case TDVI:
        tdvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case VARI:
        vari(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WV_VI:
        wv_vi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MCARI:
        mcari(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MCARI2:
        mcari2(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MRENDVI:
        mrendvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MRESR:
        mresr(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MTVI:
        mtvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MTVI2:
        mtvi2(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case RENDVI:
        rendvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case REPI:
        repi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case TCARI:
        tcari(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case TVI:
        tvi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case VREI1:
        vrei1(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case VREI2:
        vrei2(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDNI:
        ndni(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case MSI:
        msi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDII:
        ndii(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDWI:
        ndwi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NMDI:
        nmdi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case WBI:
        wbi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case NDLI:
        ndli(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case CAI:
        cai(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case PSRI:
        psri(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case ARI1:
        ari1(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case ARI2:
        ari2(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case CRI1:
        cri1(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case CRI2:
        cri2(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case PRI:
        pri(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case SIPI:
        sipi(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    case RGRI:
        rgri(raw_data, x, y, z, value_array_of_all_band, result);
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

//以下为一个计算NDVI的示例，可以作为如何使用本函数库的参考示例
// testing
int main(int argc, const char **argv)
{
    int raw[2][2][5] = {
        {{0, 289, 0, 3550, 0},
         {0, 232, 0, 2769, 0}},
        {{0, 1453, 0, 1986, 0},
         {0, 3273, 0, 3419, 0}}};
    // float result[2][2];
    float **result = new float *[2];
    for (int i = 0; i < 2; ++i)
    {
        result[i] = new float[2];
    }
    float a[5] = {600, 649, 800, 850, 960};
    int ***raw_data = new int **[2];
    for (int i = 0; i < 2; ++i)
    {
        raw_data[i] = new int *[2];
        for (int j = 0; j < 2; ++j)
        {
            raw_data[i][j] = new int[5];
            for (int k = 0; k < 5; ++k)
            {
                raw_data[i][j][k] = raw[i][j][k];
            }
        }
    }
    spectral_index_calculation(raw_data, 2, 2, 5, a, NDVI, result);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "ndvi is " << result[i][j] << endl;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            delete[] raw_data[i][j];
        }
        delete[] raw_data[i];
    }
    delete[] raw_data;
    for (int i = 0; i < 2; ++i)
    {
        delete[] result[i];
    }
    delete[] result;
    return 0;
}
