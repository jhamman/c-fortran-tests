
#include <test.h>

void
print_cn_structure(size_t Nbands, size_t Nnode, cn_data_struct **cn)
{
    size_t iband, iveg, k;

    fprintf(stderr, "cn_data:\n");

    for(iband = 0; iband < Nbands; iband++) {
        fprintf(stderr, "Band: %zu\n", iband);
        for(iveg = 0; iveg < MAX_PFT; iveg++) {
            fprintf(stderr, "Band: %zu, VEG: %zu\n", iband, iveg);
            fprintf(stderr, "LAI                    : %.4f\n", (*cn)[iband].LAI[iveg]);
            fprintf(stderr, "dormant_flag           : %.4f\n", (*cn)[iband].dormant_flag[iveg]);
            fprintf(stderr, "days_active            : %.4f\n", (*cn)[iband].days_active[iveg]);
            fprintf(stderr, "onset_flag             : %.4f\n", (*cn)[iband].onset_flag[iveg]);
            fprintf(stderr, "onset_counter          : %.4f\n", (*cn)[iband].onset_counter[iveg]);
            fprintf(stderr, "onset_gddflag          : %.4f\n", (*cn)[iband].onset_gddflag[iveg]);
            fprintf(stderr, "onset_fdd              : %.4f\n", (*cn)[iband].onset_fdd[iveg]);
            fprintf(stderr, "onset_gdd              : %.4f\n", (*cn)[iband].onset_gdd[iveg]);
            fprintf(stderr, "onset_swi              : %.4f\n", (*cn)[iband].onset_swi[iveg]);
            fprintf(stderr, "offset_flag            : %.4f\n", (*cn)[iband].offset_flag[iveg]);
            fprintf(stderr, "offset_counter         : %.4f\n", (*cn)[iband].offset_counter[iveg]);
            fprintf(stderr, "offset_fdd             : %.4f\n", (*cn)[iband].offset_fdd[iveg]);
            fprintf(stderr, "offset_swi             : %.4f\n", (*cn)[iband].offset_swi[iveg]);
            fprintf(stderr, "lgsf                   : %.4f\n", (*cn)[iband].lgsf[iveg]);
            fprintf(stderr, "bglfr                  : %.4f\n", (*cn)[iband].bglfr[iveg]);
            fprintf(stderr, "bgtr                   : %.4f\n", (*cn)[iband].bgtr[iveg]);
            fprintf(stderr, "dayl                   : %.4f\n", (*cn)[iband].dayl[iveg]);
            fprintf(stderr, "prev_dayl              : %.4f\n", (*cn)[iband].prev_dayl[iveg]);
            fprintf(stderr, "annavg_t2m             : %.4f\n", (*cn)[iband].annavg_t2m[iveg]);
            fprintf(stderr, "tempavg_t2m            : %.4f\n", (*cn)[iband].tempavg_t2m[iveg]);
            fprintf(stderr, "gpp2                   : %.4f\n", (*cn)[iband].gpp2[iveg]);
            fprintf(stderr, "availc                 : %.4f\n", (*cn)[iband].availc[iveg]);
            fprintf(stderr, "xsmrpool_recover       : %.4f\n", (*cn)[iband].xsmrpool_recover[iveg]);
            fprintf(stderr, "alloc_pnow             : %.4f\n", (*cn)[iband].alloc_pnow[iveg]);
            fprintf(stderr, "c_allometry            : %.4f\n", (*cn)[iband].c_allometry[iveg]);
            fprintf(stderr, "n_allometry            : %.4f\n", (*cn)[iband].n_allometry[iveg]);
            fprintf(stderr, "tempsum_potential_gpp  : %.4f\n", (*cn)[iband].tempsum_potential_gpp[iveg]);
            fprintf(stderr, "annsum_potential_gpp   : %.4f\n", (*cn)[iband].annsum_potential_gpp[iveg]);
            fprintf(stderr, "tempmax_retransn       : %.4f\n", (*cn)[iband].tempmax_retransn[iveg]);
            fprintf(stderr, "annmax_retransn        : %.4f\n", (*cn)[iband].annmax_retransn[iveg]);
            fprintf(stderr, "avail_retransn         : %.4f\n", (*cn)[iband].avail_retransn[iveg]);
            fprintf(stderr, "plant_nalloc           : %.4f\n", (*cn)[iband].plant_nalloc[iveg]);
            fprintf(stderr, "plant_calloc           : %.4f\n", (*cn)[iband].plant_calloc[iveg]);
            fprintf(stderr, "excess_cflux           : %.4f\n", (*cn)[iband].excess_cflux[iveg]);
            fprintf(stderr, "downreg                : %.4f\n", (*cn)[iband].downreg[iveg]);
            fprintf(stderr, "prev_leafc_to_litter   : %.4f\n", (*cn)[iband].prev_leafc_to_litter[iveg]);
            fprintf(stderr, "prev_frootc_to_litter  : %.4f\n", (*cn)[iband].prev_frootc_to_litter[iveg]);
            fprintf(stderr, "tempsum_npp            : %.4f\n", (*cn)[iband].tempsum_npp[iveg]);
            fprintf(stderr, "annsum_npp             : %.4f\n", (*cn)[iband].annsum_npp[iveg]);
            fprintf(stderr, "gpp                    : %.4f\n", (*cn)[iband].gpp[iveg]);
            fprintf(stderr, "npp                    : %.4f\n", (*cn)[iband].npp[iveg]);
            fprintf(stderr, "ar                     : %.4f\n", (*cn)[iband].ar[iveg]);
            fprintf(stderr, "leafc                  : %.4f\n", (*cn)[iband].leafc[iveg]);
            fprintf(stderr, "leafc_storage          : %.4f\n", (*cn)[iband].leafc_storage[iveg]);
            fprintf(stderr, "leafc_xfer             : %.4f\n", (*cn)[iband].leafc_xfer[iveg]);
            fprintf(stderr, "frootc                 : %.4f\n", (*cn)[iband].frootc[iveg]);
            fprintf(stderr, "frootc_storage         : %.4f\n", (*cn)[iband].frootc_storage[iveg]);
            fprintf(stderr, "frootc_xfer            : %.4f\n", (*cn)[iband].frootc_xfer[iveg]);
            fprintf(stderr, "livestemc              : %.4f\n", (*cn)[iband].livestemc[iveg]);
            fprintf(stderr, "livestemc_storage      : %.4f\n", (*cn)[iband].livestemc_storage[iveg]);
            fprintf(stderr, "livestemc_xfer         : %.4f\n", (*cn)[iband].livestemc_xfer[iveg]);
            fprintf(stderr, "deadstemc              : %.4f\n", (*cn)[iband].deadstemc[iveg]);
            fprintf(stderr, "deadstemc_storage      : %.4f\n", (*cn)[iband].deadstemc_storage[iveg]);
            fprintf(stderr, "deadstemc_xfer         : %.4f\n", (*cn)[iband].deadstemc_xfer[iveg]);
            fprintf(stderr, "livecrootc             : %.4f\n", (*cn)[iband].livecrootc[iveg]);
            fprintf(stderr, "livecrootc_storage     : %.4f\n", (*cn)[iband].livecrootc_storage[iveg]);
            fprintf(stderr, "livecrootc_xfer        : %.4f\n", (*cn)[iband].livecrootc_xfer[iveg]);
            fprintf(stderr, "deadcrootc             : %.4f\n", (*cn)[iband].deadcrootc[iveg]);
            fprintf(stderr, "deadcrootc_storage     : %.4f\n", (*cn)[iband].deadcrootc_storage[iveg]);
            fprintf(stderr, "deadcrootc_xfer        : %.4f\n", (*cn)[iband].deadcrootc_xfer[iveg]);
            fprintf(stderr, "gresp_storage          : %.4f\n", (*cn)[iband].gresp_storage[iveg]);
            fprintf(stderr, "gresp_xfer             : %.4f\n", (*cn)[iband].gresp_xfer[iveg]);
            fprintf(stderr, "cpool                  : %.4f\n", (*cn)[iband].cpool[iveg]);
            fprintf(stderr, "xsmrpool               : %.4f\n", (*cn)[iband].xsmrpool[iveg]);
            fprintf(stderr, "pft_ctrunc             : %.4f\n", (*cn)[iband].pft_ctrunc[iveg]);
            fprintf(stderr, "totvegc                : %.4f\n", (*cn)[iband].totvegc[iveg]);
            fprintf(stderr, "woodc                  : %.4f\n", (*cn)[iband].woodc[iveg]);
            fprintf(stderr, "leafn                  : %.4f\n", (*cn)[iband].leafn[iveg]);
            fprintf(stderr, "leafn_storage          : %.4f\n", (*cn)[iband].leafn_storage[iveg]);
            fprintf(stderr, "leafn_xfer             : %.4f\n", (*cn)[iband].leafn_xfer[iveg]);
            fprintf(stderr, "frootn                 : %.4f\n", (*cn)[iband].frootn[iveg]);
            fprintf(stderr, "frootn_storage         : %.4f\n", (*cn)[iband].frootn_storage[iveg]);
            fprintf(stderr, "frootn_xfer            : %.4f\n", (*cn)[iband].frootn_xfer[iveg]);
            fprintf(stderr, "livestemn              : %.4f\n", (*cn)[iband].livestemn[iveg]);
            fprintf(stderr, "livestemn_storage      : %.4f\n", (*cn)[iband].livestemn_storage[iveg]);
            fprintf(stderr, "livestemn_xfer         : %.4f\n", (*cn)[iband].livestemn_xfer[iveg]);
            fprintf(stderr, "deadstemn              : %.4f\n", (*cn)[iband].deadstemn[iveg]);
            fprintf(stderr, "deadstemn_storage      : %.4f\n", (*cn)[iband].deadstemn_storage[iveg]);
            fprintf(stderr, "deadstemn_xfer         : %.4f\n", (*cn)[iband].deadstemn_xfer[iveg]);
            fprintf(stderr, "livecrootn             : %.4f\n", (*cn)[iband].livecrootn[iveg]);
            fprintf(stderr, "livecrootn_storage     : %.4f\n", (*cn)[iband].livecrootn_storage[iveg]);
            fprintf(stderr, "livecrootn_xfer        : %.4f\n", (*cn)[iband].livecrootn_xfer[iveg]);
            fprintf(stderr, "deadcrootn             : %.4f\n", (*cn)[iband].deadcrootn[iveg]);
            fprintf(stderr, "deadcrootn_storage     : %.4f\n", (*cn)[iband].deadcrootn_storage[iveg]);
            fprintf(stderr, "deadcrootn_xfer        : %.4f\n", (*cn)[iband].deadcrootn_xfer[iveg]);
            fprintf(stderr, "retransn               : %.4f\n", (*cn)[iband].retransn[iveg]);
            fprintf(stderr, "npool                  : %.4f\n", (*cn)[iband].npool[iveg]);
            fprintf(stderr, "pft_ntrunc             : %.4f\n", (*cn)[iband].pft_ntrunc[iveg]);
        }

        fprintf(stderr, "decl                   : %.4f\n", (*cn)[iband].decl);
        fprintf(stderr, "fpi                    : %.4f\n", (*cn)[iband].fpi);
        fprintf(stderr, "fpg                    : %.4f\n", (*cn)[iband].fpg);
        fprintf(stderr, "annsum_counter         : %.4f\n", (*cn)[iband].annsum_counter);
        fprintf(stderr, "cannsum_npp            : %.4f\n", (*cn)[iband].cannsum_npp);
        fprintf(stderr, "cannavg_t2m            : %.4f\n", (*cn)[iband].cannavg_t2m);
        for(k = 0; k < Nnode; k++) {
            fprintf(stderr, "Band: %zu, Node: %zu\n", iband, k);
            fprintf(stderr, "watfc                  : %.4f\n", (*cn)[iband].watfc[k]);
        }
        fprintf(stderr, "me                     : %.4f\n", (*cn)[iband].me);
        fprintf(stderr, "fire_prob              : %.4f\n", (*cn)[iband].fire_prob);
        fprintf(stderr, "mean_fire_prob         : %.4f\n", (*cn)[iband].mean_fire_prob);
        fprintf(stderr, "fireseasonl            : %.4f\n", (*cn)[iband].fireseasonl);
        fprintf(stderr, "ann_farea_burned       : %.4f\n", (*cn)[iband].ann_farea_burned);
        fprintf(stderr, "cwdc                   : %.4f\n", (*cn)[iband].cwdc);
        fprintf(stderr, "litr1c                 : %.4f\n", (*cn)[iband].litr1c);
        fprintf(stderr, "litr2c                 : %.4f\n", (*cn)[iband].litr2c);
        fprintf(stderr, "litr3c                 : %.4f\n", (*cn)[iband].litr3c);
        fprintf(stderr, "soil1c                 : %.4f\n", (*cn)[iband].soil1c);
        fprintf(stderr, "soil2c                 : %.4f\n", (*cn)[iband].soil2c);
        fprintf(stderr, "soil3c                 : %.4f\n", (*cn)[iband].soil3c);
        fprintf(stderr, "soil4c                 : %.4f\n", (*cn)[iband].soil4c);
        fprintf(stderr, "seedc                  : %.4f\n", (*cn)[iband].seedc);
        fprintf(stderr, "col_ctrunc             : %.4f\n", (*cn)[iband].col_ctrunc);
        fprintf(stderr, "totlitc                : %.4f\n", (*cn)[iband].totlitc);
        fprintf(stderr, "totsomc                : %.4f\n", (*cn)[iband].totsomc);
        fprintf(stderr, "totcolc                : %.4f\n", (*cn)[iband].totcolc);
        fprintf(stderr, "prod10c                : %.4f\n", (*cn)[iband].prod10c);
        fprintf(stderr, "prod100c               : %.4f\n", (*cn)[iband].prod100c);
        fprintf(stderr, "cwdn                   : %.4f\n", (*cn)[iband].cwdn);
        fprintf(stderr, "litr1n                 : %.4f\n", (*cn)[iband].litr1n);
        fprintf(stderr, "litr2n                 : %.4f\n", (*cn)[iband].litr2n);
        fprintf(stderr, "litr3n                 : %.4f\n", (*cn)[iband].litr3n);
        fprintf(stderr, "soil1n                 : %.4f\n", (*cn)[iband].soil1n);
        fprintf(stderr, "soil2n                 : %.4f\n", (*cn)[iband].soil2n);
        fprintf(stderr, "soil3n                 : %.4f\n", (*cn)[iband].soil3n);
        fprintf(stderr, "soil4n                 : %.4f\n", (*cn)[iband].soil4n);
        fprintf(stderr, "sminn                  : %.4f\n", (*cn)[iband].sminn);
        fprintf(stderr, "seedn                  : %.4f\n", (*cn)[iband].seedn);
        fprintf(stderr, "col_ntrunc             : %.4f\n", (*cn)[iband].col_ntrunc);
        fprintf(stderr, "totcoln                : %.4f\n", (*cn)[iband].totcoln);
        fprintf(stderr, "prod10n                : %.4f\n", (*cn)[iband].prod10n);
        fprintf(stderr, "prod100n               : %.4f\n", (*cn)[iband].prod100n);
        fprintf(stderr, "hr                     : %.4f\n", (*cn)[iband].hr);
        fprintf(stderr, "nee                    : %.4f\n", (*cn)[iband].nee);
        fprintf(stderr, "nep                    : %.4f\n", (*cn)[iband].nep);
    }
}
