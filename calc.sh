echo "SIMPLE CALCULATOR MENU"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "Choose an operation:"
read ch
echo "Enter first number: "
read x
echo "Enter second number: "
read y
case $ch in
1)sum=$(($x+$y))
echo "Sum =" $sum;;
2)diff=$(($x-$y))
echo "Difference =" $diff;;
3)prod=$(($x*$y))
echo "Product =" $prod;;
4)res=$(($x/$y))
echo "Result =" $res;;
*)echo "Invalid Choice";;
esac
