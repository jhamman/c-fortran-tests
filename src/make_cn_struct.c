
#include <test.h>

/**
 * @brief Create CN Data Structure
 * @details This function allocates and initializes a CN data structure
 *
 * @param Nbands Number of elevation bands [1, max_bands]
 * @param Nnode Number of soil temperature nodes [1, max_nodes]
 * @param cn Pointer to complete CN data structure
 */
void
make_cn_struct(size_t Nbands, size_t Nnode, cn_data_struct **cn)
{

    size_t iband, iveg, k;

    *cn = (cn_data_struct *) calloc(Nbands, sizeof(cn_data_struct));

    for(iband = 0; iband < Nbands; iband++) {
        for(iveg = 0; iveg < MAX_PFT; iveg++) {
            (*cn)[iband].LAI[iveg] = MISSING;
            (*cn)[iband].dormant_flag[iveg] = MISSING;
            (*cn)[iband].days_active[iveg] = MISSING;
            (*cn)[iband].onset_flag[iveg] = MISSING;
            (*cn)[iband].onset_counter[iveg] = MISSING;
            (*cn)[iband].onset_gddflag[iveg] = MISSING;
            (*cn)[iband].onset_fdd[iveg] = MISSING;
            (*cn)[iband].onset_gdd[iveg] = MISSING;
            (*cn)[iband].onset_swi[iveg] = MISSING;
            (*cn)[iband].offset_flag[iveg] = MISSING;
            (*cn)[iband].offset_counter[iveg] = MISSING;
            (*cn)[iband].offset_fdd[iveg] = MISSING;
            (*cn)[iband].offset_swi[iveg] = MISSING;
            (*cn)[iband].lgsf[iveg] = MISSING;
            (*cn)[iband].bglfr[iveg] = MISSING;
            (*cn)[iband].bgtr[iveg] = MISSING;
            (*cn)[iband].dayl[iveg] = MISSING;
            (*cn)[iband].prev_dayl[iveg] = MISSING;
            (*cn)[iband].annavg_t2m[iveg] = MISSING;
            (*cn)[iband].tempavg_t2m[iveg] = MISSING;
            (*cn)[iband].gpp2[iveg] = MISSING;
            (*cn)[iband].availc[iveg] = MISSING;
            (*cn)[iband].xsmrpool_recover[iveg] = MISSING;
            (*cn)[iband].alloc_pnow[iveg] = MISSING;
            (*cn)[iband].c_allometry[iveg] = MISSING;
            (*cn)[iband].n_allometry[iveg] = MISSING;
            (*cn)[iband].tempsum_potential_gpp[iveg] = MISSING;
            (*cn)[iband].annsum_potential_gpp[iveg] = MISSING;
            (*cn)[iband].tempmax_retransn[iveg] = MISSING;
            (*cn)[iband].annmax_retransn[iveg] = MISSING;
            (*cn)[iband].avail_retransn[iveg] = MISSING;
            (*cn)[iband].plant_nalloc[iveg] = MISSING;
            (*cn)[iband].plant_calloc[iveg] = MISSING;
            (*cn)[iband].excess_cflux[iveg] = MISSING;
            (*cn)[iband].downreg[iveg] = MISSING;
            (*cn)[iband].prev_leafc_to_litter[iveg] = MISSING;
            (*cn)[iband].prev_frootc_to_litter[iveg] = MISSING;
            (*cn)[iband].tempsum_npp[iveg] = MISSING;
            (*cn)[iband].annsum_npp[iveg] = MISSING;
            (*cn)[iband].gpp[iveg] = MISSING;
            (*cn)[iband].npp[iveg] = MISSING;
            (*cn)[iband].ar[iveg] = MISSING;
            (*cn)[iband].leafc[iveg] = MISSING;
            (*cn)[iband].leafc_storage[iveg] = MISSING;
            (*cn)[iband].leafc_xfer[iveg] = MISSING;
            (*cn)[iband].frootc[iveg] = MISSING;
            (*cn)[iband].frootc_storage[iveg] = MISSING;
            (*cn)[iband].frootc_xfer[iveg] = MISSING;
            (*cn)[iband].livestemc[iveg] = MISSING;
            (*cn)[iband].livestemc_storage[iveg] = MISSING;
            (*cn)[iband].livestemc_xfer[iveg] = MISSING;
            (*cn)[iband].deadstemc[iveg] = MISSING;
            (*cn)[iband].deadstemc_storage[iveg] = MISSING;
            (*cn)[iband].deadstemc_xfer[iveg] = MISSING;
            (*cn)[iband].livecrootc[iveg] = MISSING;
            (*cn)[iband].livecrootc_storage[iveg] = MISSING;
            (*cn)[iband].livecrootc_xfer[iveg] = MISSING;
            (*cn)[iband].deadcrootc[iveg] = MISSING;
            (*cn)[iband].deadcrootc_storage[iveg] = MISSING;
            (*cn)[iband].deadcrootc_xfer[iveg] = MISSING;
            (*cn)[iband].gresp_storage[iveg] = MISSING;
            (*cn)[iband].gresp_xfer[iveg] = MISSING;
            (*cn)[iband].cpool[iveg] = MISSING;
            (*cn)[iband].xsmrpool[iveg] = MISSING;
            (*cn)[iband].pft_ctrunc[iveg] = MISSING;
            (*cn)[iband].totvegc[iveg] = MISSING;
            (*cn)[iband].woodc[iveg] = MISSING;
            (*cn)[iband].leafn[iveg] = MISSING;
            (*cn)[iband].leafn_storage[iveg] = MISSING;
            (*cn)[iband].leafn_xfer[iveg] = MISSING;
            (*cn)[iband].frootn[iveg] = MISSING;
            (*cn)[iband].frootn_storage[iveg] = MISSING;
            (*cn)[iband].frootn_xfer[iveg] = MISSING;
            (*cn)[iband].livestemn[iveg] = MISSING;
            (*cn)[iband].livestemn_storage[iveg] = MISSING;
            (*cn)[iband].livestemn_xfer[iveg] = MISSING;
            (*cn)[iband].deadstemn[iveg] = MISSING;
            (*cn)[iband].deadstemn_storage[iveg] = MISSING;
            (*cn)[iband].deadstemn_xfer[iveg] = MISSING;
            (*cn)[iband].livecrootn[iveg] = MISSING;
            (*cn)[iband].livecrootn_storage[iveg] = MISSING;
            (*cn)[iband].livecrootn_xfer[iveg] = MISSING;
            (*cn)[iband].deadcrootn[iveg] = MISSING;
            (*cn)[iband].deadcrootn_storage[iveg] = MISSING;
            (*cn)[iband].deadcrootn_xfer[iveg] = MISSING;
            (*cn)[iband].retransn[iveg] = MISSING;
            (*cn)[iband].npool[iveg] = MISSING;
            (*cn)[iband].pft_ntrunc[iveg] = MISSING;
        }

        (*cn)[iband].decl = MISSING;
        (*cn)[iband].fpi = MISSING;
        (*cn)[iband].fpg = MISSING;
        (*cn)[iband].annsum_counter = MISSING;
        (*cn)[iband].cannsum_npp = MISSING;
        (*cn)[iband].cannavg_t2m = MISSING;
        for(k = 0; k < Nnode; k++)
            (*cn)[iband].watfc[k] = MISSING;
        (*cn)[iband].me = MISSING;
        (*cn)[iband].fire_prob = MISSING;
        (*cn)[iband].mean_fire_prob = MISSING;
        (*cn)[iband].fireseasonl = MISSING;
        (*cn)[iband].ann_farea_burned = MISSING;
        (*cn)[iband].cwdc = MISSING;
        (*cn)[iband].litr1c = MISSING;
        (*cn)[iband].litr2c = MISSING;
        (*cn)[iband].litr3c = MISSING;
        (*cn)[iband].soil1c = MISSING;
        (*cn)[iband].soil2c = MISSING;
        (*cn)[iband].soil3c = MISSING;
        (*cn)[iband].soil4c = MISSING;
        (*cn)[iband].seedc = MISSING;
        (*cn)[iband].col_ctrunc = MISSING;
        (*cn)[iband].totlitc = MISSING;
        (*cn)[iband].totsomc = MISSING;
        (*cn)[iband].totcolc = MISSING;
        (*cn)[iband].prod10c = MISSING;
        (*cn)[iband].prod100c = MISSING;
        (*cn)[iband].cwdn = MISSING;
        (*cn)[iband].litr1n = MISSING;
        (*cn)[iband].litr2n = MISSING;
        (*cn)[iband].litr3n = MISSING;
        (*cn)[iband].soil1n = MISSING;
        (*cn)[iband].soil2n = MISSING;
        (*cn)[iband].soil3n = MISSING;
        (*cn)[iband].soil4n = MISSING;
        (*cn)[iband].sminn = MISSING;
        (*cn)[iband].seedn = MISSING;
        (*cn)[iband].col_ntrunc = MISSING;
        (*cn)[iband].totcoln = MISSING;
        (*cn)[iband].prod10n = MISSING;
        (*cn)[iband].prod100n = MISSING;
        (*cn)[iband].hr = MISSING;
        (*cn)[iband].nee = MISSING;
        (*cn)[iband].nep = MISSING;
    }
}

/**
 * @brief Free CN data sturcture memory
 */
void
free_cn(cn_data_struct **cn)
/***************************************************************************
  Modifications:
***************************************************************************/
{

  if (*cn == NULL)
    return;

  free(*cn);
}
