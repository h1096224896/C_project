def merge_lists(list1, list2):
    for item in list2:
        if item not in list1:
            list1.append(item)
    return list1

def main():
    list1 = [1, 2, 3]
    list2 = [4, 5, 6]
    print(merge_lists(list1, list2))

if __name__ == '__main__':
    main()
