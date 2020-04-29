import csv
import matplotlib.pyplot as plt
import statistics as sta
import numpy as np
def main():
    data=[]
    l_str_data=[]
    l_float_data=[]
    with open("ToFdata.csv","r") as f:
        reader=csv.reader(f)
        l_str_data=[row for row in reader]
        for i in range(181):
            data.append([float(s) for s in l_str_data[i]])
        #for i in range(19):
        #    data.append([i*10,sta.median(l_float_data[i])])
    #print(data)
    print(data)
    ax=plt.subplot(projection="polar")
    for i in range(181):
        ax.scatter(np.deg2rad(data[i][0]),data[i][1],c="blue",s=15)
    plt.savefig("search_ToF.png")
    plt.show()
if __name__ == "__main__":
    main()
