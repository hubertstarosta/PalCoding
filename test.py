import tkinter as tk


def open_new_window(category):
    window = tk.Toplevel(root)
    window.title("Insurance Coverage Cards")
    window.geometry("700x700")

    label = tk.Label(window, text=category, font=('Times New Roman', 30))
    label.grid(row=0, column=0)

    


def Sfunction(event):
    text = search.get()
    matching_categories = []

    for drug_list in types[1]:
        if text.lower() in [d.lower() for d in drug_list]:
            category = types[0][types[1].index(drug_list)]
            matching_categories.append(category)

    if matching_categories:
        listbox.delete(0, tk.END)

        for category in matching_categories:
            listbox.insert(tk.END, category)

    else:
        listbox.delete(0, tk.END)
        listbox.insert(tk.END, "Drug Not Available")

def on_select(event):
    selected_category = listbox.get(listbox.curselection())
    open_new_window(selected_category)

root = tk.Tk()
root.title("Drugs")
root.config(background='#5A96E3')
root.geometry("700x700")

root.columnconfigure(0, weight=1)
root.rowconfigure(0, weight=1)
root.rowconfigure(1, weight=1)
root.rowconfigure(2, weight=1)
root.rowconfigure(3, weight=1)

search = tk.Entry(root)
label = tk.Label(root)
header = tk.Label(root)

listbox = tk.Listbox(root, height=5, width=30, font=('Times New Roman', 16), bg = '#0A6EBD')
listbox.grid(row=3, pady=(0,50), sticky='N')


button = tk.Button(root, command=lambda: new(), highlightbackground="#5A96E3", fg='#E7CEA6', bg = '#0A6EBD')
button.config(text='Search')
button.config(font={'Times New Roman'})
#button.config()
button.grid(row=2, pady=(0,30), sticky='N')
types = [['innovicares', 'RxHelp'], [
    ['Abilify', 'Adderall XR', 'Advagraf', 'Advair Diskus', 'Amerge', 'APPRILON', 'Arimidex', 'Avodart', 'Azilect', 
     'BEZALIP SR', 'Biphentin', 'BRILINTA', 'Casodex', 'Celexa', 'CellCept', 'Cesamet', 'Cipralex', 'COMBIGAN', 'Concerta', 
     'Coversyl', 'Coversyl Plus', 'Coversyl Plus HD', 'Crestor', 'Cymbalta', 'Diamicron MR', 'Dificid', 'Duotrav PQ', 'Elocom', 
     'Ezetrol', 'Faslodex', 'FLOVENT HFA', 'FORXIGA', 'Fosavance', 'FOSRENOL', 'GE200 Glucose Test Strips', 'Glumetza', 'Imitrex DF', 
     'INTUNIV XR', 'Iressa', 'Lamictal', 'LATUDA', 'LOKELMA', 'Losec', 'LOTRIDERM', 'Marvelon', 'Maxalt RPD', 'Maxalt', 'MEPRON', 'Nasonex', 
     'Nexium', 'Onglyza', 'Paxil', 'Plendil', 'Prezista', 'Prograf', 'Prometrium', 'Propecia', 'Proscar', 'Prozac', 'Pulmicort Nebuamp', 
     'Restasis Multi-Dose', 'Restasis', 'Rocaltrol', 'Sensipar', 'Seroquel XR', 'Seroquel IR', 'Singulair', 'Soriatane', 'Strattera', 'Sublinox', 
     'TACTUPUMP', 'TACTUPUMP FORTE', 'Tamiflu', 'Tarceva', 'Tenormin', 'Valcyte', 'Valtrex', 'Vasotec', 'Vimovo', 'Wellbutrin XL', 'XARELTO', 'XIGDUO', 
     'Zestoretic', 'Zestril', 'Zocor', 'Zomig Rapimelt', 'Zomig', 'Zovirax'], 
     
     ['Accupril', 'Accuretic', 'Actonel DR', 'Alesse', 'Androgel', 'Arava', 'Aricept', 'ARIMIDEX', 'Arixtra', 'Arthrotec', 
     'AVALIDE', 'AVAPRO', 'Biaxin BID', 'Biaxin', 'BRILINTA', 'Bystolic', 'Caduet', 'CASODEX', 'Celebrex', 'CellCept', 
     'Concerta', 'Cosopt', 'CRESTOR', 'Detrol', 'Detrol LA', 'Dicetel', 'Diclectin', 'Dymista', 'Ebixa', 'ELIQUIS', 'Elocom', 
     'Epival', 'Ezetrol', 'Fosavance', 'GLUCOPHAGE', 'IMOVANE', 'Invanz', 'Isoptin', 'LOSEC', 'Lotriderm', 'Luvox', 'Lyrica', 
     'Marvelon', 'Mavik', 'Maxalt RPD', 'Maxalt', 'Nasonex', 'NEXIUM', 'NITROLINGUAL_PUMPSPRAY', 'ONGLYZA', 'OTEZLA', 'Pantoloc', 
     'PLAQUENIL', 'PLAVIX', 'PLENDIL', 'Posanol', 'Prevacid', 'Prometrium', 'Propecia', 'Proscar', 'Relpax', 'RILUTEK', 'Rocaltrol', 
     'Rythmol', 'SERC', 'SEROQUEL', 'SEROQUEL XR', 'Singulair', 'Sporanox', 'STRATTERA', 'Tamiflu', 'Tarceva', 'Tecta', 'Temodal', 
     'TENORMIN', 'VFEND', 'Vimovo', 'Xalacom', 'Xalatan', 'XATRAL', 'XELJANZ', 'ZESTORETIC', 'ZESTRIL', 'Zocor', 'Zoloft', 'ZOMIG', 
     'ZOMIG RAPIMELT', 'Zytiga']]]







def new():
    Sfunction(None)

header.config(text="Coverage Offered At: ", font=('Times New Roman', 20, 'bold'), background='#5A96E3', fg='#E7CEA6')
header.grid(row=2, pady=(75,10), sticky='S')

label.config(text='Search your drug')
label.config(background='#5A96E3', fg='#E7CEA6')
label.config(font=('Times New Roman', 50, 'bold'))
label.grid(row=0, pady=(75,10), sticky='S')

search.bind('<Return>', Sfunction)
search.config(highlightbackground='#5A96E3', bg='#0A6EBD', fg = '#E7CEA6')
search.grid(row=1, sticky='N')

listbox.bind('<Double-Button-1>', on_select)


root.mainloop()
