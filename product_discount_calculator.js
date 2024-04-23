// please install prompt-sync package by running npm install prompt-sync in the terminal before running this code
const prompt = require(prompt-sync)();

let productCost = [20, 40, 50]
let productQunatity = [0, 0, 0]
let productName = ['A', 'B', 'C']
let giftWrap = [0, 0, 0]

let totalProdct = 0
let totalProductCost = 0
let totalGiftWrapCost = 0
let faltTenDiscount = 0
let bulkFiveDiscount = 0
let bulkTenDiscount = 0
let tieredFiftyDiscount = 0
let mostDiscounted = [0, 0, 0, 0]




for(let product = 1 ; product <= 3 ; product++){
    productQunatity[product-1] = parseInt(prompt(`Enter the quantity of product ${productName[product-1]}: `))
    giftWrap[product-1] = parseInt(prompt(`Do you want to gift wrap product ${productName[product-1]} (1 for yes, 0 for no): `))

    totalProductCost += productCost[product-1] * productQunatity[product-1] 
    totalProdct += productQunatity[product-1]
    totalGiftWrapCost += giftWrap[product-1] * productQunatity[product-1]

    if(productQunatity[product-1] > 10){
        bulkFiveDiscount += productCost[product-1] * productQunatity[product-1] * 0.05
    }
}

if(totalProductCost >= 200){
  faltTenDiscount = 10;
}

if(totalProdct > 20){
  bulkTenDiscount = totalProductCost * 0.1
}

if(totalProdct >= 30){
  for(let  product = 0; product < 3; product++){
    let leftAfterFifteenProduct = productQunatity[product] - 15
    if(leftAfterFifteenProduct > 0){
      tieredFiftyDiscount += productCost[product] * leftAfterFifteenProduct * 0.5
    }
  }
}

mostDiscounted[0] = faltTenDiscount
mostDiscounted[1] = bulkFiveDiscount
mostDiscounted[2] = bulkTenDiscount
mostDiscounted[3] = tieredFiftyDiscount

let maxDiscountIndex = mostDiscounted.indexOf(Math.max(...mostDiscounted))
let discountName = ["Flat 10 discount", "Bulk 5% discount", "Bulk 10% discount",  "Tiered 50% discount"]
let shippingCost = Math.ceil(totalProdct/10) * 5


for(let product = 1; product <= 3; product++){
  console.log( product ${productName[product-1]}, quantity: ${productQunatity[product-1]}, cost: ${productCost[product-1] * productQunatity[product-1] })
}

console.log(subtotal: ${totalProductCost})
console.log(discount name: ${discountName[maxDiscountIndex]} discount cost: ${mostDiscounted[maxDiscountIndex]})
console.log(shipping fee & gift wrap fee: ${shippingCost + totalGiftWrapCost})

let totalCost = totalProductCost - mostDiscounted[maxDiscountIndex] + shippingCost + totalGiftWrapCost
console.log(total cost: ${totalCost})
