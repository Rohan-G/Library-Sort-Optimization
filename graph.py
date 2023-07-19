import matplotlib.pyplot as plt
import numpy as np
import random

l = ["QSort", "Merge", "Insertion"]
l2 = ["Library", "Optimized"]
l3 = l+l2

# graphing best of all epsilon for lib/opt

g = []

f = open("./ansReverse.txt", "r")

# for i in l:
#     x = f.readline()
#     while x != '':
#         x = x.split(' ')
#         if (x[0] == i):
#             g.append([i, int(x[1]), float(x[2][:-1])])
#         x = f.readline()
#     f.seek(0)

# for i in l2:
#     x = f.readline()
#     # if (len(x) > 2 and x[1] == "Epsilon" and x[2] == "2"):
#     #     g.append([i, int(x[3]), int(x[4])])

#     while x != '':
#         x = x.split(' ')
#         # print(x)
#         if (len(x) > 2 and x[0] == i and x[1] == "Epsilon" and x[2] == "2"):
#             g.append([i, int(x[3]), float(x[4][:-1])])
#         x = f.readline()
#     f.seek(0)

x = f.readline()
while(x!=''):
    # print(x)
    x = x.split(' ')
    # print(x)
    if(x[0]!='Optimized'):
        x = f.readline()
        continue
    g.append((int(x[2]),int(x[3]),float(x[4])))
    x = f.readline()

# sorted_g = sorted(g, key=lambda x:x[1])
# print(g)
npg = np.array(g, dtype=object)
# for i in range(len(npg)):
#     npg[i][1] = int(npg[i][1])

# print(npg)

sorted = npg[npg[:, 1].argsort()]

# print(sorted)

dx = [sorted[0][1]]
dy=[[]]
num = 0
prev = sorted[0][1]

for i in sorted:
    if(i[1] == prev):
        dy[num].append([i[0],i[2]])
    else:
        prev = i[1]
        num+=1
        # plt.bar(dx, dy, bottom=bot, color=r[random.randint(0, 2)])
        dx.append(prev)
        dy.append([[i[0],i[2]]])
        # bot = dy

print(len(dx),len(dy))

colors={1:"red", 2:"blue", 3:"green", 4:"yellow", 5:"purple", 6:"orange", 7:"pink", 8:"brown", 9:"indigo", 10:"black"}

# Create the bar graph
fig, ax = plt.subplots()
bars = []
labels = []
width = 0.08
for i in range(15,20):
    for j in range(len(dy[i])):
        x_pos = i - 5*width + (j * width)
        group, value = dy[i][j]
        color = colors.get(group, 'black')
        # print(color, value)
        # print(x_pos,value)
        bar = ax.bar(x_pos, value, width, color=color)
        bars.append(bar)
        if group not in labels:
            labels.append(group)

# Add labels and legend
ax.set_xticks(range(15,20))
ax.set_xticklabels(dx[10:])
ax.set_ylabel('Time in Seconds')
ax.set_xlabel('Size of array')
ax.set_title('Bar Graph')
ax.legend(bars,labels)

# Display the graph
plt.show()

# print(sorted)
# x = l3

# print(dx,dy)

# colors = ['r', 'g', 'b', 'c', 'm']

# # x = 11
# dx = [sorted[0][1]]
# dy = [[]]
# prev = sorted[0][1]
# num = 0
# # bot = [0, 0, 0, 0, 0]
# for i in sorted:
#     if (i[1] == prev):
#         dy[num].append([i[0],i[2]])
#     else:
#         prev = i[1]
#         num+=1
#         # plt.bar(dx, dy, bottom=bot, color=r[random.randint(0, 2)])
#         dx.append(prev)
#         dy.append([[i[0],i[2]]])
#         # bot = dy
# # plt.bar(dx, dy, bottom=bot)
# # dx = []
# # dy = []

# # print(dx,dy)

# # Define a dictionary of colors for each group
# colors = {"Insertion": 'red', "QSort": 'blue', "Library": 'green', "Optimized":'yellow', "Merge":'Orange'}

# bars = []
# labels = []

# print(len(dx))

# # Create the bar graph
# fig, ax = plt.subplots()
# width = 0.15
# for i in range(15,len(dx)):
#     for j in range(len(dy[i])):
#         x_pos = i - 2*width + (j * width)
#         group, value = dy[i][j]
#         color = colors.get(group, 'black')
#         # print(color, value)
#         # print(x_pos,value)
#         bar = ax.bar(x_pos, value, width, color=color)
#         bars.append(bar)
#         if group not in labels:
#             labels.append(group)

# # Add labels and legend
# ax.set_xticks(range(15,len(dx)))
# ax.set_xticklabels(dx[15:])
# ax.set_ylabel('Value')
# ax.set_title('Bar Graph')
# ax.legend(bars,labels)

# # Display the graph
# plt.show()

# # print(sorted)
# # x = l3



