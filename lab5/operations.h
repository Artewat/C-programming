double** create_matrix(int n);
void free_matrix(double** matrix, int n);
double** add_matrices(double** a, double** b, int n);
double** subtract_matrices(double** a, double** b, int n);
double** multiply_matrices(double** a, double** b, int n);
double** perform_operation(double** a, double** b, int n, char operation);