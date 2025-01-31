echo "Enter the limit: "
read n
x=0
y=1
echo "The fibonacci sequence is: "
for((i=1;i<=n;i++))
do
echo $x
f=$(($x+$y))
x=$y
y=$f
done
