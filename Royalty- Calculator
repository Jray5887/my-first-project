#include <iostream>
#include <iomanip>

using namespace std;

// Constants for royalty rates and fixed payments
const double OPTION1_ADVANCE = 5000.0;
const double OPTION1_PUBLICATION = 20000.0;
const double OPTION2_RATE = 0.125;
const double OPTION3_RATE1 = 0.10;
const double OPTION3_RATE2 = 0.14;
const int OPTION3_THRESHOLD = 4000;

int main() {
    double netPrice;
    int estimatedCopies;
    
    // Prompt user for input
    cout << "Enter the net price of each copy: ";
    cin >> netPrice;
    cout << "Enter the estimated number of copies to be sold: ";
    cin >> estimatedCopies;
    
    // Calculate royalties for each option
    double royaltiesOption1 = OPTION1_ADVANCE + OPTION1_PUBLICATION;
    double royaltiesOption2 = OPTION2_RATE * netPrice * estimatedCopies;
    double royaltiesOption3;
    
    if (estimatedCopies <= OPTION3_THRESHOLD) {
        royaltiesOption3 = OPTION3_RATE1 * netPrice * estimatedCopies;
    } else {
        royaltiesOption3 = (OPTION3_RATE1 * netPrice * OPTION3_THRESHOLD) + 
                           (OPTION3_RATE2 * netPrice * (estimatedCopies - OPTION3_THRESHOLD));
    }
    
    // Display the royalties for each option
    cout << fixed << setprecision(2);
    cout << "\nRoyalties under each option:" << endl;
    cout << "Option 1: $" << royaltiesOption1 << endl;
    cout << "Option 2: $" << royaltiesOption2 << endl;
    cout << "Option 3: $" << royaltiesOption3 << endl;
    
    // Determine the best option
    double bestRoyalties = max(royaltiesOption1, max(royaltiesOption2, royaltiesOption3));
    cout << "\nThe best option is: ";
    if (bestRoyalties == royaltiesOption1)
        cout << "Option 1";
    else if (bestRoyalties == royaltiesOption2)
        cout << "Option 2";
    else
        cout << "Option 3";
    
    cout << " with earnings of $" << bestRoyalties << endl;
    
    return 0;
}
