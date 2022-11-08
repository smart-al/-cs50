while True:
    # Use try statement to avoid value error
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            for i in range(height, 0, -1):
                print(" " * (i - 1), end='')
                print("#" * (height - (i - 1)))
            break
    except:
        continue
