#include <stdio.h>

// Function prototypes
void updateSectorStatus(int grid[5][5], int rows, int cols);
void querySectorStatus(int grid[5][5], int rows, int cols);
void runSystemDiagnostic(int grid[5][5], int rows, int cols);

// main function
int main() {
    int grid[5][5] = {0};  
    int choice;

    do {
        printf("\n===== IESCO Power Grid Monitoring System =====\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                updateSectorStatus(grid, 5, 5);
                break;
            case 2:
                querySectorStatus(grid, 5, 5);
                break;
            case 3:
                runSystemDiagnostic(grid, 5, 5);
                break;
            case 4:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}




void updateSectorStatus(int grid[5][5], int rows, int cols) {
    int row, col, flag, action;

    printf("Enter sector row (0-%d): ", rows-1);
    scanf("%d", &row);
    printf("Enter sector col (0-%d): ", cols-1);
    scanf("%d", &col);

    if(row < 0 || row >= rows || col < 0 || col >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nSelect flag to modify:\n");
    printf("1. Power Status\n");
    printf("2. Overload Warning\n");
    printf("3. Maintenance Required\n");
    printf("Enter choice: ");
    scanf("%d", &flag);

    printf("1. Set flag (turn ON)\n");
    printf("2. Clear flag (turn OFF)\n");
    printf("Enter action: ");
    scanf("%d", &action);

    int bitMask = 1 << (flag - 1);  

    if(action == 1)
        grid[row][col] |= bitMask;   
    else if(action == 2)
        grid[row][col] &= ~bitMask;  
    else {
        printf("Invalid action!\n");
        return;
    }

    printf("Sector [%d][%d] updated successfully!\n", row, col);
}




void querySectorStatus(int grid[5][5], int rows, int cols) {
    int row, col;
    printf("Enter sector row (0-%d): ", rows-1);
    scanf("%d", &row);
    printf("Enter sector col (0-%d): ", cols-1);
    scanf("%d", &col);

    if(row < 0 || row >= rows || col < 0 || col >= cols) {
        printf("Invalid coordinates!\n");
        return;
    }

    int value = grid[row][col];
    printf("\n===== Sector [%d][%d] Status =====\n", row, col);
    printf("Power Status       : %s\n", (value & 1) ? "ON" : "OFF");
    printf("Overload Warning   : %s\n", (value & 2) ? "OVERLOADED" : "Normal");
    printf("Maintenance Needed : %s\n", (value & 4) ? "YES" : "NO");
}



void runSystemDiagnostic(int grid[5][5], int rows, int cols) {
    int overloadCount = 0, maintenanceCount = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] & 2)  
                overloadCount++;
            if(grid[i][j] & 4)  
                maintenanceCount++;
        }
    }

    printf("\n===== System Diagnostic Report =====\n");
    printf("Total Overloaded Sectors   : %d\n", overloadCount);
    printf("Total Maintenance Required : %d\n", maintenanceCount);
}

