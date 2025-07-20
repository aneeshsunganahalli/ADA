set title "Consecutive Integer Checking Algorithm Analysis"
set xrange [0:500]
set yrange [0:100]
set xlabel "Input Size"
set ylabel "Operations Count"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ConsecutiveInt_Small.txt" title "Small Numbers", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ConsecutiveInt_Medium.txt" title "Medium Numbers", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\GCDAlgorithms\\ConsecutiveInt_Large.txt" title "Large Numbers"
