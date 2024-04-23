
products = {
    "Product A": 20,
    "Product B": 40,
    "Product C": 50
}

discount_rules = {
    "flat_10_discount": {"threshold": 200, "discount": 10},
    "bulk_5_discount": {"quantity": 10, "discount_percent": 5},
    "bulk_10_discount": {"total_quantity": 20, "discount_percent": 10},
    "tiered_50_discount": {"total_quantity": 30, "single_product_quantity": 15, "discount_percent": 50}
}


gift_wrap_fee = 1
shipping_fee_per_package = 5
units_per_package = 10


def calculate_discount(cart_total, quantities):
    applicable_discounts = {}
    for rule, details in discount_rules.items():
        if rule == "flat_10_discount" and cart_total >= details["threshold"]:
            applicable_discounts[rule] = details["discount"]
        elif rule == "bulk_10_discount" and sum(quantities.values()) >= details["total_quantity"]:
            applicable_discounts[rule] = details["discount_percent"]
        elif rule == "tiered_50_discount" and any(qty > details["single_product_quantity"] for qty in quantities.values()) and sum(quantities.values()) >= details["total_quantity"]:
            applicable_discounts[rule] = details["discount_percent"]
    if applicable_discounts:
        max_discount_rule = max(applicable_discounts, key=applicable_discounts.get)
        return max_discount_rule, applicable_discounts[max_discount_rule]
    return None, 0

def calculate_shipping_fee(total_units):
    return (total_units // units_per_package) * shipping_fee_per_package


def calculate_total_cost(cart_total, discount, shipping_fee, gift_wrap_fee):
    return cart_total - discount + shipping_fee + gift_wrap_fee


quantities = {}
for product in products:
    quantity = int(input(f"Enter the quantity of {product}: "))
    quantities[product] = quantity
    gift_wrap = int(input(f"Do you want to gift wrap {product}? (1 for yes, 0 for no): "))
    if gift_wrap:
        gift_wrap_fee += quantity


cart_total = sum(products[product] * quantities[product] for product in quantities)


discount_rule, discount_amount = calculate_discount(cart_total, quantities)


shipping_fee = calculate_shipping_fee(sum(quantities.values()))


total_cost = calculate_total_cost(cart_total, discount_amount, shipping_fee, gift_wrap_fee)


print("Product Details:")
for product, quantity in quantities.items():
    print(f"{product}: Quantity - {quantity}, Total Amount - ${products[product] * quantity}")

print(f"\nSubtotal: ${cart_total}")
if discount_rule:
    print(f"Discount Applied: {discount_rule.replace('_', ' ').title()}, Amount - ${discount_amount}")
print(f"Shipping Fee: ${shipping_fee}")
print(f"Gift Wrap Fee: ${gift_wrap_fee}")
print(f"\nTotal Cost: ${total_cost}")
