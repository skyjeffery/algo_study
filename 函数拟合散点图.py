import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt 
from sklearn.model_selection import GridSearchCV, train_test_split
from sklearn.metrics import r2_score, mean_squared_error
from scipy.optimize import curve_fit


print("==================1.数据读取=================")
print("==================2.数据预处理=================")
#得到x和y的值
x = np.random.randint(1,31,size = 1000)
y = np.random.randint(1,91,size = 1000)
print("==================4.可视化输出=================")

##仅可视化散点图
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['figure.dpi'] = 120 
plt.figure(figsize=(6, 4))
plt.scatter(x, y, color='#1f77b4', alpha=0.6
            ,edgecolors='w', s=100)
#x轴和y轴标签
plt.xlabel('离任务最近的五个用户距离均值(km)',fontsize=12)
plt.ylabel("定价(元)",fontsize=12)
plt.xlim(0,30)
plt.xticks([0,10,20,30],fontsize=10,rotation=45)
plt.ylim(60,90)
plt.title('任务定价与最近用户平均距离关系图',fontsize=14)
plt.show()
plt.close()


##曲线拟合
#拟合函数
def log_func(x,a,b,c):
    return a * np.log(x+b) + c

#拟合参数初始值
initial_params = [10, 1, 70]

#设置参数边界（可选）- 例如，a在5到20之间，b在0.5到5之间，c在60到80之间
bounds = (
    [5, 0.5, 60],   # 下界
    [20, 5, 80]     # 上界
)



params, params_cov = curve_fit(
    log_func, 
    x , y,
    p0=initial_params,
    bounds=bounds,maxfev=10000)
a, b, c = params
print(f"拟合参数：a={a:.3f}, b={b:.3f}, c={c:.3f}")

#可视化拟合函数
a_ltx = f"{a:.3f}"; b_ltx = f"{b:.3f}"; c_ltx = f"{c:.3f}"
eqa = rf"定价 = {a_ltx}·ln(距离+{b_ltx}) + {c_ltx}"


x_plot = np.linspace(min(x), max(x), 100)
y_plot = log_func(x_plot, a, b, c)

#可视化
plt.figure(figsize=(6, 4))
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams['figure.dpi'] = 120 
plt.scatter(x, y, color='#1f77b4', alpha=0.6
            ,edgecolors='w', s=100, label='数据点') 
plt.plot(x_plot, y_plot, color='red', linewidth=2, label='拟合曲线')
plt.text(10, 80, eqa, fontsize=12, color='red')
plt.xlabel('离任务最近的五个用户距离均值(km)',fontsize=12)
plt.ylabel("定价(元)",fontsize=12)  
plt.xlim(0,30)
plt.xticks([0,10,20,30],fontsize=10,rotation=45)
plt.ylim(60,90)         
plt.title('任务定价与最近用户平均距离回归分析',fontsize=14)
plt.legend()    
plt.show()
plt.close()


print("==================5.评估拟合效果=================")
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2,random_state=42)

x_train_pred = log_func(x_train.ravel(),*params)
x_test_pred = log_func(x_test.ravel(),*params)

# 计算R²和MSE
r2_score_train = r2_score(y_train,x_train_pred)
mse_train = mean_squared_error(y_train,x_train_pred)
r2_score_test = r2_score(y_test,x_test_pred)
mse_test = mean_squared_error(y_test,x_test_pred)

print(f"训练集R²得分：{r2_score_train:.4f}")
print(f"训练集MSE：{mse_train:.4f}")
print(f"测试集R²得分：{r2_score_test:.4f}")
print(f"测试集MSE：{mse_test:.4f}")