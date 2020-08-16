import tkinter as tk
import math

window = tk.Tk()
window.title('Setup')
window.geometry('800x600')
window.configure(background='white')

def save_results():
    cpus = int(cpus_entry.get())
    result = 'CPU number: {}'.format(cpus)
    result_label.configure(text=result)
    createCFile(result)

def createCFile(result):
    f = open("config.h", "w")
    f.write(result)
    f.close()

header_label = tk.Label(window, text='Setup')
header_label.pack()

cpus_frame = tk.Frame(window)
cpus_frame.pack(side=tk.TOP)
cpus_label = tk.Label(cpus_frame, text='CPU number')
cpus_label.pack(side=tk.LEFT)
cpus_entry = tk.Entry(cpus_frame)
cpus_entry.pack(side=tk.LEFT)

result_label = tk.Label(window)
result_label.pack()

save_btn = tk.Button(window, text='SAVE', command=save_results)
save_btn.pack()

window.mainloop()

