import time, tkinter as tk, math, random, subprocess

from pythonlibs import pylib

root = tk.Tk()
root.title("Secure Guard")

master_frame = tk.Frame(root, background="grey", width=800, height=600)
master_frame.grid(row=0,column=0)

side_frame = tk.Frame(master_frame, background="dark grey", width=250, height=600)
side_frame.grid(row=0, column=0)

scan_button = tk.Button(side_frame, background="grey", text="Scan", width=20, height=2, command=lambda: pylib.SpawnNotification("Why won't it work?", "You have to buy the PRO version!", "grey", "black", 24)
)
scan_button.grid(row=0, column=0)

titfle_label = tk.Label(master_frame, background="grey", foreground="black", font="Arial 24 bold", text=" ")
titfle_label.grid(row=0, column=1)

title_label = tk.Label(master_frame, background="grey", foreground="black", font="Arial 24 bold", text="Welcome to Secure Guard!")
title_label.grid(row=0, column=2)

description = tk.Label(master_frame, background="grey", foreground="black", font="Arial 18 bold", text="Hello there user! Choose your action. REMINDER! You still have to activate your AV.")
description.grid(row=1,column=2)

warning = tk.Label(master_frame, background="grey", foreground="red", font="Arial 12 bold", text="You have active threats on your computer! Scan now to see them!")
warning.grid(row=2, column=2, pady=20)







root.mainloop()