#!/usr/bin/gnuplot -persist
set grid
plot "result.txt" u (column(0)):3:xtic(2) w l title "" 
