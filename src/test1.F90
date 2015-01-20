
subroutine use_cn_data_struct(Nbands, Nnodes, Npfts, cn_data) BIND(C, name='use_cn_data_struct')
    USE, INTRINSIC :: ISO_C_BINDING
    implicit none

    integer(C_SIZE_T), intent(in), value :: Nbands
    integer(C_SIZE_T), intent(in), value :: Nnodes
    integer(C_SIZE_T), intent(in), value :: Npfts

    TYPE, BIND(C) :: vic_cn_data_type
        ! PFT-level ecophysiological variables
        REAL(C_DOUBLE) :: LAI(21);                   ! leaf area index
        REAL(C_DOUBLE) :: dormant_flag(21);          ! dormancy flag
        REAL(C_DOUBLE) :: days_active(21);           ! # days since last dormancy
        REAL(C_DOUBLE) :: onset_flag(21);            ! onset flag
        REAL(C_DOUBLE) :: onset_counter(21);         ! onset days counter
        REAL(C_DOUBLE) :: onset_gddflag(21);         ! onset flag for growing deg day sum
        REAL(C_DOUBLE) :: onset_fdd(21);             ! onset freezing deg day counter
        REAL(C_DOUBLE) :: onset_gdd(21);             ! onset growing degree days
        REAL(C_DOUBLE) :: onset_swi(21);             ! onset soil water index
        REAL(C_DOUBLE) :: offset_flag(21);           ! offset flag
        REAL(C_DOUBLE) :: offset_counter(21);        ! offset days counter
        REAL(C_DOUBLE) :: offset_fdd(21);            ! offset freezing deg day counter
        REAL(C_DOUBLE) :: offset_swi(21);            ! offset soil water index
        REAL(C_DOUBLE) :: lgsf(21);                  ! long growing season factor
        REAL(C_DOUBLE) :: bglfr(21);                 ! background litterfall rate (1/s)
        REAL(C_DOUBLE) :: bgtr(21);                  ! background transfer growth rate (1/s)
        REAL(C_DOUBLE) :: dayl(21);                  ! daylength (s)
        REAL(C_DOUBLE) :: prev_dayl(21);             ! daylength at previous timestep (s)
        REAL(C_DOUBLE) :: annavg_t2m(21);            ! annual average 2-m air temperature (K)
        REAL(C_DOUBLE) :: tempavg_t2m(21);           ! temporary average 2-m air temperature (K)
        REAL(C_DOUBLE) :: gpp2(21);                  ! GPP flux before downregulation (g C/m^2/s)
        REAL(C_DOUBLE) :: availc(21);                ! C flux available for allocation (g C/m^2/s)
        REAL(C_DOUBLE) :: xsmrpool_recover(21);      ! C flux assigned to recovery (g C/m^2/s)
        REAL(C_DOUBLE) :: alloc_pnow(21);            ! fraction of current allocation as new growth
        REAL(C_DOUBLE) :: c_allometry(21);           ! C allocation index
        REAL(C_DOUBLE) :: n_allometry(21);           ! N allocation index
        REAL(C_DOUBLE) :: plant_ndemand(21);         ! N flux required to support GPP (g N/m^2/s)
        REAL(C_DOUBLE) :: tempsum_potential_gpp(21); ! temporary annual sum of potential GPP
        REAL(C_DOUBLE) :: annsum_potential_gpp(21);  ! annuals sum of potential GPP
        REAL(C_DOUBLE) :: tempmax_retransn(21);      ! temporary annual max of retrans N pool (g N/m^2)
        REAL(C_DOUBLE) :: annmax_retransn(21);       ! annual max of retransloc N pool (g N/m^2)
        REAL(C_DOUBLE) :: avail_retransn(21);        ! N flux avail for retransloc (g N/m^2/s)
        REAL(C_DOUBLE) :: plant_nalloc(21);          ! total allocated N flux (g N/m^2/s)
        REAL(C_DOUBLE) :: plant_calloc(21);          ! total allocated C flux (g C/m^2/s)
        REAL(C_DOUBLE) :: excess_cflux(21);          ! C flux not allocated (g C/m^2/s)
        REAL(C_DOUBLE) :: downreg(21);               ! fract reduction in GPP due to N limit
        REAL(C_DOUBLE) :: prev_leafc_to_litter(21);  ! previous leaf C litterfall (g C/m^2/s)
        REAL(C_DOUBLE) :: prev_frootc_to_litter(21); ! previous froot C litterfall (g C/m^2/s)
        REAL(C_DOUBLE) :: tempsum_npp(21);           ! temporary annual sum of NPP (g C/m^2/yr)
        REAL(C_DOUBLE) :: annsum_npp(21);            ! annual sum of NPP (g C/m^2/yr)
        REAL(C_DOUBLE) :: gpp(21);                   ! gross primary production (g C/m^2/s)
        REAL(C_DOUBLE) :: npp(21);                   ! net primary production (g C/m^2/s)
        REAL(C_DOUBLE) :: ar(21);                    ! autotrophic respiration (g C/m^2/s)
        ! PFT-level carbon state
        REAL(C_DOUBLE) :: leafc(21);                 ! leaf C (g C/m^2)
        REAL(C_DOUBLE) :: leafc_storage(21);         ! leaf C storage (g C/m^2)
        REAL(C_DOUBLE) :: leafc_xfer(21);            ! leaf C transfer (g C/m^2)
        REAL(C_DOUBLE) :: frootc(21);                ! fine root C (g C/m^2)
        REAL(C_DOUBLE) :: frootc_storage(21);        ! fine root C storage (g C/m^2)
        REAL(C_DOUBLE) :: frootc_xfer(21);           ! fine root C transfer (g C/m^2)
        REAL(C_DOUBLE) :: livestemc(21);             ! live stem C (g C/m^2)
        REAL(C_DOUBLE) :: livestemc_storage(21);     ! live stem C storage (g C/m^2)
        REAL(C_DOUBLE) :: livestemc_xfer(21);        ! live stem C transfer (g C/m^2)
        REAL(C_DOUBLE) :: deadstemc(21);             ! dead stem C (g C/m^2)
        REAL(C_DOUBLE) :: deadstemc_storage(21);     ! dead stem C storage (g C/m^2)
        REAL(C_DOUBLE) :: deadstemc_xfer(21);        ! dead stem C transfer (g C/m^2)
        REAL(C_DOUBLE) :: livecrootc(21);            ! live coarse root C (g C/m^2)
        REAL(C_DOUBLE) :: livecrootc_storage(21);    ! live coarse root C storage (g C/m^2)
        REAL(C_DOUBLE) :: livecrootc_xfer(21);       ! live coarse root C transfer (g C/m^2)
        REAL(C_DOUBLE) :: deadcrootc(21);            ! dead coarse root C (g C/m^2)
        REAL(C_DOUBLE) :: deadcrootc_storage(21);    ! dead coarse root C storage (g C/m^2)
        REAL(C_DOUBLE) :: deadcrootc_xfer(21);       ! dead coarse root C transfer (g C/m^2)
        REAL(C_DOUBLE) :: gresp_storage(21);         ! growth respiration storage (g C/m^2)
        REAL(C_DOUBLE) :: gresp_xfer(21);            ! growth respiration transfer (g C/m^2)
        REAL(C_DOUBLE) :: cpool(21);                 ! temporary photosynthate C pool (g C/m^2)
        REAL(C_DOUBLE) :: xsmrpool(21);              ! abstract C pool to meet excess MR demand (g C/m^2)
        REAL(C_DOUBLE) :: pft_ctrunc(21);            ! PFT-level sink for C truncation (g C/m^2)
        REAL(C_DOUBLE) :: totvegc(21);               ! total vegetation C (g C/m^2)
        REAL(C_DOUBLE) :: woodc(21);                 ! wood C (g C/m^2)
        ! PFT-level nitrogen state
        REAL(C_DOUBLE) :: leafn(21);                 ! leaf N (g N/m^2)
        REAL(C_DOUBLE) :: leafn_storage(21);         ! leaf N storage (g N/m^2)
        REAL(C_DOUBLE) :: leafn_xfer(21);            ! leaf N transfer (g N/m^2)
        REAL(C_DOUBLE) :: frootn(21);                ! fine root N (g N/m^2)
        REAL(C_DOUBLE) :: frootn_storage(21);        ! fine root N storage (g N/m^2)
        REAL(C_DOUBLE) :: frootn_xfer(21);           ! fine root N transfer (g N/m^2)
        REAL(C_DOUBLE) :: livestemn(21);             ! live stem N (g N/m^2)
        REAL(C_DOUBLE) :: livestemn_storage(21);     ! live stem N storage (g N/m^2)
        REAL(C_DOUBLE) :: livestemn_xfer(21);        ! live stem N transfer (g N/m^2)
        REAL(C_DOUBLE) :: deadstemn(21);             ! dead stem N (g N/m^2)
        REAL(C_DOUBLE) :: deadstemn_storage(21);     ! dead stem N storage (g N/m^2)
        REAL(C_DOUBLE) :: deadstemn_xfer(21);        ! dead stem N transfer (g N/m^2)
        REAL(C_DOUBLE) :: livecrootn(21);            ! live coarse root N (g N/m^2)
        REAL(C_DOUBLE) :: livecrootn_storage(21);    ! live coarse root N storage (g N/m^2)
        REAL(C_DOUBLE) :: livecrootn_xfer(21);       ! live coarse root N transfer (g N/m^2)
        REAL(C_DOUBLE) :: deadcrootn(21);            ! dead coarse root N (g N/m^2)
        REAL(C_DOUBLE) :: deadcrootn_storage(21);    ! dead coarse root N storage (g N/m^2)
        REAL(C_DOUBLE) :: deadcrootn_xfer(21);       ! dead coarse root N transfer (g N/m^2)
        REAL(C_DOUBLE) :: retransn(21);              ! retranslocated N (g N/m^2)

        REAL(C_DOUBLE) :: npool(21);                 ! temporary photosynthate N pool (g N/m^2)
        REAL(C_DOUBLE) :: pft_ntrunc(21);            ! PFT-level sink for N truncation (g N/m^2)
        ! column (band) physical state
        REAL(C_DOUBLE) :: decl;                      ! solar declination angle (radians)
        REAL(C_DOUBLE) :: fpi;                       ! fraction of potential immobilization
        REAL(C_DOUBLE) :: fpg;                       ! fraction of potential GPP
        REAL(C_DOUBLE) :: annsum_counter;            ! seconds since last ann accumulation turnover
        REAL(C_DOUBLE) :: cannsum_npp;               ! annual sum of NPP, averaged from PFT-level (g C/m^2/yr)
        REAL(C_DOUBLE) :: cannavg_t2m;               ! annual avg. of 2-m air temperature, averaged from PFT-level (K)
        REAL(C_DOUBLE) :: watfc(3);                  ! volumetric soil water at field capacity
        REAL(C_DOUBLE) :: me;                        ! moisture of extinction
        REAL(C_DOUBLE) :: fire_prob;                 ! daily fire probability
        REAL(C_DOUBLE) :: mean_fire_prob;            ! e-folding mean of daily fire prob.
        REAL(C_DOUBLE) :: fireseasonl;               ! annual fire season length (days)
        REAL(C_DOUBLE) :: farea_burned;              ! timestep fractional area burned
        REAL(C_DOUBLE) :: ann_farea_burned;          ! annual total fract. area burned
        REAL(C_DOUBLE) :: hr;                        ! heterotrophic respiration (g C/m^2/s)
        REAL(C_DOUBLE) :: nee;                       ! net ecosystem exchange (g C/m^2/s)
        REAL(C_DOUBLE) :: nep;                       ! net ecosystem production (g C/m^2/s)
        ! column (band) carbon state
        REAL(C_DOUBLE) :: cwdc;                      ! coarse woody debris C (g C/m^2)
        REAL(C_DOUBLE) :: litr1c;                    ! litter labile C (g C/m^2)
        REAL(C_DOUBLE) :: litr2c;                    ! litter cellulose C (g C/m^2)
        REAL(C_DOUBLE) :: litr3c;                    ! litter lignin C (g C/m^2)
        REAL(C_DOUBLE) :: soil1c;                    ! fastest soil organic matter C
        REAL(C_DOUBLE) :: soil2c;                    ! medium soil organic matter C
        REAL(C_DOUBLE) :: soil3c;                    ! slow soil organic matter C
        REAL(C_DOUBLE) :: soil4c;                    ! slowest soil organic matter C
        REAL(C_DOUBLE) :: seedc;                     ! column-lev pool for seeding new PFTs
        REAL(C_DOUBLE) :: col_ctrunc;                ! column-lev sink for C truncation
        REAL(C_DOUBLE) :: totlitc;                   ! total litter C (g C/m^2)
        REAL(C_DOUBLE) :: totsomc;                   ! total soil organic C (g C/m^2)
        REAL(C_DOUBLE) :: totcolc;                   ! total column C (g C/m^2)
        REAL(C_DOUBLE) :: prod10c;                   ! wood product C pool, 10-yr lifespan (g C/m^2)
        REAL(C_DOUBLE) :: prod100c;                  ! wood product C pool, 100-yr lifespan (g C/m^2)
        ! column (band) nitrogen state
        REAL(C_DOUBLE) :: cwdn;                      ! coarse woody debris N (g N/m^2)
        REAL(C_DOUBLE) :: litr1n;                    ! litter labile N (g N/m^2)
        REAL(C_DOUBLE) :: litr2n;                    ! litter cellulose N (g N/m^2)
        REAL(C_DOUBLE) :: litr3n;                    ! litter lignin N (g N/m^2)
        REAL(C_DOUBLE) :: soil1n;                    ! fastest soil organic matter N
        REAL(C_DOUBLE) :: soil2n;                    ! medium soil organic matter N
        REAL(C_DOUBLE) :: soil3n;                    ! slow soil organic matter N
        REAL(C_DOUBLE) :: soil4n;                    ! slowest soil organic matter N
        REAL(C_DOUBLE) :: sminn;                     ! soil mineral N (g N/m^2)
        REAL(C_DOUBLE) :: seedn;                     ! column-lev pool for seeding new PFTs
        REAL(C_DOUBLE) :: col_ntrunc;                ! column-lev sink for N truncation
        REAL(C_DOUBLE) :: totcoln;                   ! total column N (g N/m^2)
        REAL(C_DOUBLE) :: prod10n;                   ! wood product N pool, 10-yr lifespan (g N/m^2)
        REAL(C_DOUBLE) :: prod100n;                  ! wood product N pool, 100-yr lifespan (g N/m^2)
    END TYPE vic_cn_data_type

    type(vic_cn_data_type), DIMENSION(:), intent(inout) :: cn_data

    ! Local variables
    integer :: iband, inode, iveg

    print*, "In use_cn_data_struct()"
    print*, "Printing parameters..."
    print*, "Nbands: ", Nbands
    print*, "Nnodes: ", Nnodes
    print*, "Npfts: ", Npfts

    do iband=1,Nbands
        do iveg=1,Npfts
            cn_data(iband)%LAI(iveg) = 0.0
            cn_data(iband)%dormant_flag(iveg) = 0.0
            cn_data(iband)%days_active(iveg) = 0.0
            cn_data(iband)%onset_flag(iveg) = 0.0
            cn_data(iband)%onset_counter(iveg) = 0.0
            cn_data(iband)%onset_gddflag(iveg) = 0.0
            cn_data(iband)%onset_fdd(iveg) = 0.0
            cn_data(iband)%onset_gdd(iveg) = 0.0
            cn_data(iband)%onset_swi(iveg) = 0.0
            cn_data(iband)%offset_flag(iveg) = 0.0
            cn_data(iband)%offset_counter(iveg) = 0.0
            cn_data(iband)%offset_fdd(iveg) = 0.0
            cn_data(iband)%offset_swi(iveg) = 0.0
            cn_data(iband)%lgsf(iveg) = 0.0
            cn_data(iband)%bglfr(iveg) = 0.0
            cn_data(iband)%bgtr(iveg) = 0.0
            cn_data(iband)%dayl(iveg) = 0.0
            cn_data(iband)%prev_dayl(iveg) = 0.0
            cn_data(iband)%annavg_t2m(iveg) = 0.0
            cn_data(iband)%tempavg_t2m(iveg) = 0.0
            cn_data(iband)%gpp2(iveg) = 0.0
            cn_data(iband)%availc(iveg) = 0.0
            cn_data(iband)%xsmrpool_recover(iveg) = 0.0
            cn_data(iband)%alloc_pnow(iveg) = 0.0
            cn_data(iband)%c_allometry(iveg) = 0.0
            cn_data(iband)%n_allometry(iveg) = 0.0
            cn_data(iband)%plant_ndemand(iveg) = 0.0
            cn_data(iband)%tempsum_potential_gpp(iveg) = 0.0
            cn_data(iband)%annsum_potential_gpp(iveg) = 0.0
            cn_data(iband)%tempmax_retransn(iveg) = 0.0
            cn_data(iband)%annmax_retransn(iveg) = 0.0
            cn_data(iband)%avail_retransn(iveg) = 0.0
            cn_data(iband)%plant_nalloc(iveg) = 0.0
            cn_data(iband)%plant_calloc(iveg) = 0.0
            cn_data(iband)%excess_cflux(iveg) = 0.0
            cn_data(iband)%downreg(iveg) = 0.0
            cn_data(iband)%prev_leafc_to_litter(iveg) = 0.0
            cn_data(iband)%prev_frootc_to_litter(iveg) = 0.0
            cn_data(iband)%tempsum_npp(iveg) = 0.0
            cn_data(iband)%annsum_npp(iveg) = 0.0
            cn_data(iband)%gpp(iveg) = 0.0
            cn_data(iband)%npp(iveg) = 0.0
            cn_data(iband)%ar(iveg) = 0.0
            cn_data(iband)%leafc(iveg) = 0.0
            cn_data(iband)%leafc_storage(iveg) = 0.0
            cn_data(iband)%leafc_xfer(iveg) = 0.0
            cn_data(iband)%frootc(iveg) = 0.0
            cn_data(iband)%frootc_storage(iveg) = 0.0
            cn_data(iband)%frootc_xfer(iveg) = 0.0
            cn_data(iband)%livestemc(iveg) = 0.0
            cn_data(iband)%livestemc_storage(iveg) = 0.0
            cn_data(iband)%livestemc_xfer(iveg) = 0.0
            cn_data(iband)%deadstemc(iveg) = 0.0
            cn_data(iband)%deadstemc_storage(iveg) = 0.0
            cn_data(iband)%deadstemc_xfer(iveg) = 0.0
            cn_data(iband)%livecrootc(iveg) = 0.0
            cn_data(iband)%livecrootc_storage(iveg) = 0.0
            cn_data(iband)%livecrootc_xfer(iveg) = 0.0
            cn_data(iband)%deadcrootc(iveg) = 0.0
            cn_data(iband)%deadcrootc_storage(iveg) = 0.0
            cn_data(iband)%deadcrootc_xfer(iveg) = 0.0
            cn_data(iband)%gresp_storage(iveg) = 0.0
            cn_data(iband)%gresp_xfer(iveg) = 0.0
            cn_data(iband)%cpool(iveg) = 0.0
            cn_data(iband)%xsmrpool(iveg) = 0.0
            cn_data(iband)%pft_ctrunc(iveg) = 0.0
            cn_data(iband)%totvegc(iveg) = 0.0
            cn_data(iband)%woodc(iveg) = 0.0
            cn_data(iband)%leafn(iveg) = 0.0
            cn_data(iband)%leafn_storage(iveg) = 0.0
            cn_data(iband)%leafn_xfer(iveg) = 0.0
            cn_data(iband)%frootn(iveg) = 0.0
            cn_data(iband)%frootn_storage(iveg) = 0.0
            cn_data(iband)%frootn_xfer(iveg) = 0.0
            cn_data(iband)%livestemn(iveg) = 0.0
            cn_data(iband)%livestemn_storage(iveg) = 0.0
            cn_data(iband)%livestemn_xfer(iveg) = 0.0
            cn_data(iband)%deadstemn(iveg) = 0.0
            cn_data(iband)%deadstemn_storage(iveg) = 0.0
            cn_data(iband)%deadstemn_xfer(iveg) = 0.0
            cn_data(iband)%livecrootn(iveg) = 0.0
            cn_data(iband)%livecrootn_storage(iveg) = 0.0
            cn_data(iband)%livecrootn_xfer(iveg) = 0.0
            cn_data(iband)%deadcrootn(iveg) = 0.0
            cn_data(iband)%deadcrootn_storage(iveg) = 0.0
            cn_data(iband)%deadcrootn_xfer(iveg) = 0.0
            cn_data(iband)%retransn(iveg) = 0.0
            cn_data(iband)%npool(iveg) = 0.0
            cn_data(iband)%pft_ntrunc(iveg) = 0.0
        end do
        cn_data(iband)%decl = 0.0
        cn_data(iband)%fpi = 0.0
        cn_data(iband)%fpg = 0.0
        cn_data(iband)%annsum_counter = 0.0
        cn_data(iband)%cannsum_npp = 0.0
        cn_data(iband)%cannavg_t2m = 0.0
        do inode=1,Nnodes
            cn_data(iband)%watfc(inode) = 0.0
        end do
        cn_data(iband)%me = 0.0
        cn_data(iband)%fire_prob = 0.0
        cn_data(iband)%mean_fire_prob = 0.0
        cn_data(iband)%fireseasonl = 0.0
        cn_data(iband)%farea_burned = 0.0
        cn_data(iband)%ann_farea_burned = 0.0
        cn_data(iband)%hr = 0.0
        cn_data(iband)%nee = 0.0
        cn_data(iband)%nep = 0.0
        cn_data(iband)%cwdc = 0.0
        cn_data(iband)%litr1c = 0.0
        cn_data(iband)%litr2c = 0.0
        cn_data(iband)%litr3c = 0.0
        cn_data(iband)%soil1c = 0.0
        cn_data(iband)%soil2c = 0.0
        cn_data(iband)%soil3c = 0.0
        cn_data(iband)%soil4c = 0.0
        cn_data(iband)%seedc = 0.0
        cn_data(iband)%col_ctrunc = 0.0
        cn_data(iband)%totlitc = 0.0
        cn_data(iband)%totsomc = 0.0
        cn_data(iband)%totcolc = 0.0
        cn_data(iband)%prod10c = 0.0
        cn_data(iband)%prod100c = 0.0
        cn_data(iband)%cwdn = 0.0
        cn_data(iband)%litr1n = 0.0
        cn_data(iband)%litr2n = 0.0
        cn_data(iband)%litr3n = 0.0
        cn_data(iband)%soil1n = 0.0
        cn_data(iband)%soil2n = 0.0
        cn_data(iband)%soil3n = 0.0
        cn_data(iband)%soil4n = 0.0
        cn_data(iband)%sminn = 0.0
        cn_data(iband)%seedn = 0.0
        cn_data(iband)%col_ntrunc = 0.0
        cn_data(iband)%totcoln = 0.0
        cn_data(iband)%prod10n = 0.0
        cn_data(iband)%prod100n = 0.0
    end do

    print*, "Leaving use_cn_data_struct()"

end subroutine use_cn_data_struct
