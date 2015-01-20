#include <test.h>

int
main()
{
    cn_data_struct *cn;

    fprintf(stderr, "Starting test program\n");

    // Allocate memory for cn data structure
    make_cn_struct(NBANDS, NNODES, &cn);
    if (cn == NULL) {
        fprintf(stderr, "Problem allocating memory for cn\n");
        exit(1);
    }

    // Print cn
    fprintf(stderr, "\nPrinting cn_data_struct\n");
    print_cn_structure(NBANDS, NNODES, &cn);

    // call fortran routine
    fprintf(stderr, "\nCalling fortran subroutine\n\n");
    use_cn_data_struct((size_t) NBANDS, (size_t) NNODES, (size_t) MAX_PFT,
                       cn);

    // Print cn
    fprintf(stderr, "\nPrinting cn_data_struct\n\n");
    print_cn_structure(NBANDS, NNODES, &cn);

    fprintf(stderr, "\nFinished Test\n");

    exit(0);
}
