#ifndef TEST_H
#define TEST_H

#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Global Variables
#define NBANDS 5
#define NNODES 3
#define MAX_NODES 3
#define MAX_PFT 21
#define MISSING -9999

/**
 * This structure stores CN output in CN data structure.
 */
typedef struct {
    /* PFT-level ecophysiological variables */
    double LAI[MAX_PFT];                  /* leaf area index */
    double dormant_flag[MAX_PFT];         /* dormancy flag */
    double days_active[MAX_PFT];          /* # days since last dormancy */
    double onset_flag[MAX_PFT];           /* onset flag */
    double onset_counter[MAX_PFT];        /* onset days counter */
    double onset_gddflag[MAX_PFT];        /* onset flag for growing deg day sum */
    double onset_fdd[MAX_PFT];            /* onset freezing deg day counter */
    double onset_gdd[MAX_PFT];            /* onset growing degree days */
    double onset_swi[MAX_PFT];            /* onset soil water index */
    double offset_flag[MAX_PFT];           /* offset flag */
    double offset_counter[MAX_PFT];        /* offset days counter */
    double offset_fdd[MAX_PFT];            /* offset freezing deg day counter */
    double offset_swi[MAX_PFT];            /* offset soil water index */
    double lgsf[MAX_PFT];                 /* long growing season factor */
    double bglfr[MAX_PFT];                /* background litterfall rate (1/s) */
    double bgtr[MAX_PFT];                 /* background transfer growth rate (1/s) */
    double dayl[MAX_PFT];                 /* daylength (s) */
    double prev_dayl[MAX_PFT];            /* daylength at previous timestep (s) */
    double annavg_t2m[MAX_PFT];           /* annual average 2-m air temperature (K) */
    double tempavg_t2m[MAX_PFT];          /* temporary average 2-m air temperature (K) */
    double gpp2[MAX_PFT];                  /* GPP flux before downregulation (g C/m^2/s) */
    double availc[MAX_PFT];               /* C flux available for allocation (g C/m^2/s) */
    double xsmrpool_recover[MAX_PFT];     /* C flux assigned to recovery (g C/m^2/s) */
    double alloc_pnow[MAX_PFT];           /* fraction of current allocation as new growth */
    double c_allometry[MAX_PFT];          /* C allocation index */
    double n_allometry[MAX_PFT];          /* N allocation index */
    double plant_ndemand[MAX_PFT];        /* N flux required to support GPP (g N/m^2/s) */
    double tempsum_potential_gpp[MAX_PFT]; /* temporary annual sum of potential GPP */
    double annsum_potential_gpp[MAX_PFT]; /* annuals sum of potential GPP */
    double tempmax_retransn[MAX_PFT];     /* temporary annual max of retrans N pool (g N/m^2) */
    double annmax_retransn[MAX_PFT];      /* annual max of retransloc N pool (g N/m^2) */
    double avail_retransn[MAX_PFT];       /* N flux avail for retransloc (g N/m^2/s) */
    double plant_nalloc[MAX_PFT];         /* total allocated N flux (g N/m^2/s) */
    double plant_calloc[MAX_PFT];         /* total allocated C flux (g C/m^2/s) */
    double excess_cflux[MAX_PFT];         /* C flux not allocated (g C/m^2/s) */
    double downreg[MAX_PFT];              /* fract reduction in GPP due to N limit */
    double prev_leafc_to_litter[MAX_PFT]; /* previous leaf C litterfall (g C/m^2/s) */
    double prev_frootc_to_litter[MAX_PFT]; /* previous froot C litterfall (g C/m^2/s) */
    double tempsum_npp[MAX_PFT];          /* temporary annual sum of NPP (g C/m^2/yr) */
    double annsum_npp[MAX_PFT];           /* annual sum of NPP (g C/m^2/yr) */
    double gpp[MAX_PFT];                  /* gross primary production (g C/m^2/s) */
    double npp[MAX_PFT];                  /* net primary production (g C/m^2/s) */
    double ar[MAX_PFT];                   /* autotrophic respiration (g C/m^2/s) */
    /* PFT-level carbon state */
    double leafc[MAX_PFT];                /* leaf C (g C/m^2) */
    double leafc_storage[MAX_PFT];        /* leaf C storage (g C/m^2) */
    double leafc_xfer[MAX_PFT];           /* leaf C transfer (g C/m^2) */
    double frootc[MAX_PFT];               /* fine root C (g C/m^2) */
    double frootc_storage[MAX_PFT];       /* fine root C storage (g C/m^2) */
    double frootc_xfer[MAX_PFT];          /* fine root C transfer (g C/m^2) */
    double livestemc[MAX_PFT];            /* live stem C (g C/m^2) */
    double livestemc_storage[MAX_PFT];    /* live stem C storage (g C/m^2) */
    double livestemc_xfer[MAX_PFT];       /* live stem C transfer (g C/m^2) */
    double deadstemc[MAX_PFT];            /* dead stem C (g C/m^2) */
    double deadstemc_storage[MAX_PFT];    /* dead stem C storage (g C/m^2) */
    double deadstemc_xfer[MAX_PFT];       /* dead stem C transfer (g C/m^2) */
    double livecrootc[MAX_PFT];           /* live coarse root C (g C/m^2) */
    double livecrootc_storage[MAX_PFT];   /* live coarse root C storage (g C/m^2) */
    double livecrootc_xfer[MAX_PFT];      /* live coarse root C transfer (g C/m^2) */
    double deadcrootc[MAX_PFT];           /* dead coarse root C (g C/m^2) */
    double deadcrootc_storage[MAX_PFT];   /* dead coarse root C storage (g C/m^2) */
    double deadcrootc_xfer[MAX_PFT];      /* dead coarse root C transfer (g C/m^2) */
    double gresp_storage[MAX_PFT];        /* growth respiration storage (g C/m^2) */
    double gresp_xfer[MAX_PFT];           /* growth respiration transfer (g C/m^2) */
    double cpool[MAX_PFT];                /* temporary photosynthate C pool (g C/m^2) */
    double xsmrpool[MAX_PFT];             /* abstract C pool to meet excess MR demand (g C/m^2) */
    double pft_ctrunc[MAX_PFT];           /* PFT-level sink for C truncation (g C/m^2) */
    double totvegc[MAX_PFT];              /* total vegetation C (g C/m^2) */
    double woodc[MAX_PFT];                /* wood C (g C/m^2) */
    /* PFT-level nitrogen state */
    double leafn[MAX_PFT];                /* leaf N (g N/m^2) */
    double leafn_storage[MAX_PFT];        /* leaf N storage (g N/m^2) */
    double leafn_xfer[MAX_PFT];           /* leaf N transfer (g N/m^2) */
    double frootn[MAX_PFT];               /* fine root N (g N/m^2) */
    double frootn_storage[MAX_PFT];       /* fine root N storage (g N/m^2) */
    double frootn_xfer[MAX_PFT];          /* fine root N transfer (g N/m^2) */
    double livestemn[MAX_PFT];            /* live stem N (g N/m^2) */
    double livestemn_storage[MAX_PFT];    /* live stem N storage (g N/m^2) */
    double livestemn_xfer[MAX_PFT];       /* live stem N transfer (g N/m^2) */
    double deadstemn[MAX_PFT];            /* dead stem N (g N/m^2) */
    double deadstemn_storage[MAX_PFT];    /* dead stem N storage (g N/m^2) */
    double deadstemn_xfer[MAX_PFT];       /* dead stem N transfer (g N/m^2) */
    double livecrootn[MAX_PFT];           /* live coarse root N (g N/m^2) */
    double livecrootn_storage[MAX_PFT];   /* live coarse root N storage (g N/m^2) */
    double livecrootn_xfer[MAX_PFT];      /* live coarse root N transfer (g N/m^2) */
    double deadcrootn[MAX_PFT];           /* dead coarse root N (g N/m^2) */
    double deadcrootn_storage[MAX_PFT];   /* dead coarse root N storage (g N/m^2) */
    double deadcrootn_xfer[MAX_PFT];      /* dead coarse root N transfer (g N/m^2) */
    double retransn[MAX_PFT];             /* retranslocated N (g N/m^2) */

    double npool[MAX_PFT];                /* temporary photosynthate N pool (g N/m^2) */
    double pft_ntrunc[MAX_PFT];           /* PFT-level sink for N truncation (g N/m^2) */
    /* column (band) physical state */
    double decl;                     /* solar declination angle (radians) */
    double fpi;                      /* fraction of potential immobilization */
    double fpg;                      /* fraction of potential GPP */
    double annsum_counter;           /* seconds since last ann accumulation turnover */
    double cannsum_npp;              /* annual sum of NPP, averaged from PFT-level (g C/m^2/yr) */
    double cannavg_t2m;              /* annual avg. of 2-m air temperature, averaged from PFT-level (K) */
    double watfc[MAX_NODES];         /* volumetric soil water at field capacity */
    double me;                       /* moisture of extinction */
    double fire_prob;                /* daily fire probability */
    double mean_fire_prob;           /* e-folding mean of daily fire prob. */
    double fireseasonl;              /* annual fire season length (days) */
    double farea_burned;             /* timestep fractional area burned */
    double ann_farea_burned;         /* annual total fract. area burned */
    double hr;                   /* heterotrophic respiration (g C/m^2/s) */
    double nee;                  /* net ecosystem exchange (g C/m^2/s) */
    double nep;                  /* net ecosystem production (g C/m^2/s) */
    /* column (band) carbon state */
    double cwdc;                     /* coarse woody debris C (g C/m^2) */
    double litr1c;                   /* litter labile C (g C/m^2) */
    double litr2c;                   /* litter cellulose C (g C/m^2) */
    double litr3c;                   /* litter lignin C (g C/m^2) */
    double soil1c;                   /* fastest soil organic matter C */
    double soil2c;                   /* medium soil organic matter C */
    double soil3c;                   /* slow soil organic matter C */
    double soil4c;                   /* slowest soil organic matter C */
    double seedc;                    /* column-lev pool for seeding new PFTs */
    double col_ctrunc;               /* column-lev sink for C truncation */
    double totlitc;                  /* total litter C (g C/m^2) */
    double totsomc;                  /* total soil organic C (g C/m^2) */
    double totcolc;                  /* total column C (g C/m^2) */
    double prod10c;                  /* wood product C pool, 10-yr lifespan (g C/m^2) */
    double prod100c;                 /* wood product C pool, 100-yr lifespan (g C/m^2) */
    /* column (band) nitrogen state */
    double cwdn;                     /* coarse woody debris N (g N/m^2) */
    double litr1n;                   /* litter labile N (g N/m^2) */
    double litr2n;                   /* litter cellulose N (g N/m^2) */
    double litr3n;                   /* litter lignin N (g N/m^2) */
    double soil1n;                   /* fastest soil organic matter N */
    double soil2n;                   /* medium soil organic matter N */
    double soil3n;                   /* slow soil organic matter N */
    double soil4n;                   /* slowest soil organic matter N */
    double sminn;                    /* soil mineral N (g N/m^2) */
    double seedn;                    /* column-lev pool for seeding new PFTs */
    double col_ntrunc;               /* column-lev sink for N truncation */
    double totcoln;                  /* total column N (g N/m^2) */
    double prod10n;                  /* wood product N pool, 10-yr lifespan (g N/m^2) */
    double prod100n;                  /* wood product N pool, 100-yr lifespan (g N/m^2) */
} cn_data_struct;

// C function prototypes:
void make_cn_struct(size_t Nbands, size_t Nnode, cn_data_struct **cn);
void print_cn_structure(size_t Nbands, size_t Nnodes, cn_data_struct **cn);
void free_cn(cn_data_struct **cn);
void use_cn_data_struct(size_t Nbands, size_t Nnodes, size_t Npfts,
                        cn_data_struct *cn);

#endif
