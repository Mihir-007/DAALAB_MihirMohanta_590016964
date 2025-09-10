import pandas as pd
import matplotlib.pyplot as plt

file = pd.read_csv("binary_search_data.csv")

plt.figure(figsize=(6,6))

colors = {
    "best": "green",
    "average": "orange",
    "worst": "red"
}

for test_case in file["test_case_type"].unique():
    data = file[file["test_case_type"] == test_case]
    plt.plot(data["size"],data["time_used"], marker='o', color=colors[test_case], label=test_case)

plt.xlabel("size")
plt.ylabel("time_used (microseconds)")
plt.title("binary search program time complexity")
plt.legend()
plt.grid(True)
plt.show()