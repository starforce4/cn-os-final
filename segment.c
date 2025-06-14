#include <stdio.h>

int main() {
    int i, j, size, logicalAddress;
    int baseAddress[20], segmentLimit[20], physicalAddress;
    int memoryValues[10][10];

    printf("Enter the size of the segment table: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("\nEnter information about segment %d", i);
        printf("\nEnter base address: ");
        scanf("%d", &baseAddress[i]);
        printf("Enter the limit: ");
        scanf("%d", &segmentLimit[i]);

        printf("Enter %d values for segment %d:\n", segmentLimit[i], i);
        for (j = 0; j < segmentLimit[i]; j++) {
            printf("Address %d: ", baseAddress[i] + j);
            scanf("%d", &memoryValues[i][j]);
        }
    }

   
    printf("\n\n**** SEGMENT TABLE ****\n");
    printf("Seg No.\tBase\tLimit\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", i, baseAddress[i], segmentLimit[i]);
    }

   
    printf("\nEnter segment number: ");
    scanf("%d", &i);

    if (i < 0 || i >= size) {
        printf("Invalid segment number!\n");
    } else {
        printf("Enter the logical address: ");
        scanf("%d", &logicalAddress);

        if (logicalAddress < 0 || logicalAddress >= segmentLimit[i]) {
            printf("Invalid logical address!\n");
        } else {
            physicalAddress = baseAddress[i] + logicalAddress;
            printf("\nMapped physical address is: %d", physicalAddress);
            printf("\nThe value stored at this address is: %d\n", memoryValues[i][logicalAddress]);
        }
    }

    return 0;
}