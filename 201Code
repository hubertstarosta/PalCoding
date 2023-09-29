import tkinter as tk


    
root = tk.Tk()
root.title("Drugs")

search = tk.Entry(root)
label = tk.Label(root)
label2 = tk.Label(root)
listbox = tk.Listbox(root)
listbox.grid(row=1, column=1)


button = tk.Button(root, command = lambda: new())
button.grid(row=2, column=0, padx=250, pady=100)
button.config(text='Search')
button.config(font ={'Times New Roman', 30})

              
root.config(background ='#804D5A')

types = [['Pharma', 'InovaCare'], [['Advil', 'Xanax'], ['Advil', 'Tylenol']]]
for item in types[0]:
    listbox.insert('end', item)


def Sfunction(event):
    text = search.get()
    for item in types[1]:
        for drugs in types[1]:
            if text in drugs:
                listbox.insert('end', text)
                return

def new():
    Sfunction(None)
            
label.config(text = 'Search your drug')
label.config(background='#804D5A', fg='#FFFFFF')
label.config(font=('Times New Roman', 20, 'bold'))
label.grid(row=0, column=0, padx=100, pady=75)


search.bind('<Return>', Sfunction)
search.grid(row=1, column=0)

root.mainloop()
    
