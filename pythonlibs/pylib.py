import tkinter as tk



def SpawnNotification(title, message, bgcol, textcol, text_size):
    root = tk.Tk()
    root.title(str(title))

    root.resizable(False, False)
    root.attributes("-topmost", True)

    main_frame = tk.Frame(root, background=bgcol, width=600, height=400)
    main_frame.grid(row=0, column=0)
    text = tk.Label(main_frame, background=bgcol, foreground=textcol, text=message, font=f"Arial {text_size} bold")
    text.grid(row=0,column=0)

    ok = tk.Button(main_frame, background=bgcol, foreground="black", text="OK", font=f"Arial {text_size} bold", command=lambda: SpawnNotification("Why won't it work?", "You have to buy the PRO version!", "grey", "black", 24))
    ok.grid(row=1, column=0)

    root.after(5000, root.destroy)

    root.mainloop()

