set title "Brute Force String Matching Analysis"
set xrange [0:1000]
set yrange [0:50000]
set xlabel "Text Length (N)"
set ylabel "Character Comparisons"
set style data linespoints
plot "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceWorstCase.txt" title "Worst Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceBestCase.txt" title "Best Case", "C:\\Users\\anees\\OneDrive\\Desktop\\ADA\\StringMatching\\BruteForceAvgCase.txt" title "Average Case"
