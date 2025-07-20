set title "GCD Algorithms Comparison"
set xrange [0:100]
set yrange [0:100]
set xlabel "Input Size"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\GCD_Comparison.txt" using 1:2 title "Euclid", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\GCD_Comparison.txt" using 1:3 title "Consecutive Integer", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\GCD_Comparison.txt" using 1:4 title "Modified Euclid"
