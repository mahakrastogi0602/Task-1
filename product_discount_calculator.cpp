#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    vector<int> productCost = {20, 40, 50};
    vector<int> productQuantity(3, 0);
    vector<string> productName = {"A", "B", "C"};
    vector<int> giftWrap(3, 0);

    int totalProduct = 0;
    int totalProductCost = 0;
    int totalGiftWrapCost = 0;
    int flatTenDiscount = 0;
    int bulkFiveDiscount = 0;
    int bulkTenDiscount = 0;
    int tieredFiftyDiscount = 0;

    for (int product = 0; product < 3; product++) {
        cout << "Enter the quantity of product " << productName[product] << ": ";
        cin >> productQuantity[product];
        cout << "Do you want to gift wrap product " << productName[product] << " (1 for yes, 0 for no): ";
        cin >> giftWrap[product];

        totalProductCost += productCost[product] * productQuantity[product];
        totalProduct += productQuantity[product];
        totalGiftWrapCost += giftWrap[product] * productQuantity[product];

        if (productQuantity[product] > 10) {
            bulkFiveDiscount += productCost[product] * productQuantity[product] * 0.05;
        }
    }

    if (totalProductCost >= 200) {
        flatTenDiscount = 10;
    }

    if (totalProduct > 20) {
        bulkTenDiscount = totalProductCost * 0.1;
    }

    if (totalProduct >= 30) {
        for (int product = 0; product < 3; product++) {
            int leftAfterFifteenProduct = productQuantity[product] - 15;
            if (leftAfterFifteenProduct > 0) {
                tieredFiftyDiscount += productCost[product] * leftAfterFifteenProduct * 0.5;
            }
        }
    }

    vector<int> mostDiscounted = {flatTenDiscount, bulkFiveDiscount, bulkTenDiscount, tieredFiftyDiscount};
    vector<string> discountName = {"Flat 10 discount", "Bulk 5% discount", "Bulk 10% discount", "Tiered 50% discount"};

    int maxDiscountIndex = max_element(mostDiscounted.begin(), mostDiscounted.end()) - mostDiscounted.begin();

    int shippingCost = ceil(totalProduct / 10.0) * 5;

    for (int product = 0; product < 3; product++) {
        cout << "Product " << productName[product] << ", quantity: " << productQuantity[product] << ", cost: " << productCost[product] * productQuantity[product] << endl;
    }

    cout << "Subtotal: " << totalProductCost << endl;
    cout << "Discount name: " << discountName[maxDiscountIndex] << " discount cost: " << mostDiscounted[maxDiscountIndex] << endl;
    cout << "Shipping fee & gift wrap fee: " << shippingCost + totalGiftWrapCost << endl;

    int totalCost = totalProductCost - mostDiscounted[maxDiscountIndex] + shippingCost + totalGiftWrapCost;
    cout << "Total cost: " << totalCost << endl;

    return 0;
}
