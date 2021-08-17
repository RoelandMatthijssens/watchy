
FILE_NAME = "log.txt"

# value between 1 and 100
# e.g. SAMPLES = 5, you get table with voltages for 0%, 20%, 40%, 60%, 80% and 100% battery capacity
# e.g. SAMPLES = 100, you get table for every percentage of battery capacity
SAMPLES = 5

def guess_percentage(voltage):
	if (voltage > 4.19):
		approx_percentage = 100;
	elif (voltage <= 3.50):
		approx_percentage = 0;
	else:
		approx_percentage = 2808.3808 * pow(voltage, 4) - 43560.9157 * pow(voltage, 3) + 252848.5888 * pow(voltage, 2) - 650767.4615 * voltage + 626532.5703
	approx_percentage = round(approx_percentage)
	return approx_percentage



file = open(FILE_NAME, "r")
lines = file.readlines()
table_format = "{0}\t{1}\t{2}\t{3}\t{4}%"

print(table_format.format("%", "volt", "volt2", "time", "estimated"))
print("-------------------------------------------")
for percentage in range(0, 101, int(100/SAMPLES)): 
	line_index = round((1-(percentage/100))*(len(lines)-1))
	timestamp = lines[line_index].strip().split(",")[0]
	voltage = float(lines[line_index].strip().split(",")[1])
	voltage2 = float(lines[line_index].strip().split(",")[2])
	approx_percentage = guess_percentage(voltage)
	print(table_format.format(percentage, voltage, voltage2, timestamp, approx_percentage))

