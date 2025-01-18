void save_to_csv(const char *filename) {
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write header row
    fprintf(file, "Cx,Cy,Cn,Ck\n");

    // Write data rows
    for (int i = 0; i < size; i++) {
        fprintf(file, "%f,%f,%f,%f\n", Cx[i], Cy[i], Cn[i], Ck[i]);
    }

    fclose(file);
    printf("Data successfully saved to %s\n", filename);
}
