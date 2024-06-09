StartPointer=-1
FreeListPtr=0
NULLPOINTER=-1
List=[]
class ListNode:
    def __init__(self):
        self.Data = ""
        self.Pointer = NULLPOINTER
def InitialseList():
    global List,StartPointer,FreeListPtr
    List = [ListNode() for i in range(8)]
    StartPointer = NULLPOINTER
    FreeListPtr = 0
    for Index in range(7):
        List[Index].Pointer = Index + 1
    List[7].Pointer = NULLPOINTER

def InsertNodeAtBeg(NewItem):
    global List,StartPointer,FreeListPtr
    if FreeListPtr != NULLPOINTER:
        NewNodePtr = FreeListPtr
        List[NewNodePtr].Data = NewItem
        FreeListPtr = List[FreeListPtr].Pointer
        List[NewNodePtr].Pointer = StartPointer
        StartPointer = NewNodePtr
    else:
        print("No more space to add")
def InsertNodeAtEnd(NewItem):
    global List,StartPointer,FreeListPtr
    if FreeListPtr != NULLPOINTER:
        NewNodePtr = FreeListPtr
        List[NewNodePtr].Data = NewItem
        FreeListPtr = List[FreeListPtr].Pointer
        PreviousNodePtr = NULLPOINTER
        ThisNodePtr = StartPointer
        while ThisNodePtr != NULLPOINTER:
            PreviousNodePtr = ThisNodePtr
            ThisNodePtr = List[ThisNodePtr].Pointer
        List[NewNodePtr].Pointer = List[PreviousNodePtr].Pointer
        List[PreviousNodePtr].Pointer = NewNodePtr
    else:
        print("No more space to add")

def FindNode(DataItem):
    global List,StartPointer,FreeListPtr
    CurrentNodePtr = StartPointer
    while CurrentNodePtr != NULLPOINTER and List[CurrentNodePtr].Data != DataItem:
        CurrentNodePtr = List[CurrentNodePtr].Pointer
    return(CurrentNodePtr)

def DeleteNode(DataItem):
    global List,StartPointer,FreeListPtr
    ThisNodePtr = StartPointer  
    while ThisNodePtr != NULLPOINTER and List[ThisNodePtr].Data != DataItem:
        PreviousNodePtr = ThisNodePtr
        ThisNodePtr = List[ThisNodePtr].Pointer
    if ThisNodePtr != NULLPOINTER:
        if ThisNodePtr == StartPointer:
            StartPointer = List[StartPointer].Pointer
        else:
            List[PreviousNodePtr].Pointer = List[ThisNodePtr].Pointer
        List[ThisNodePtr].Pointer  = FreeListPtr
        FreeListPtr = ThisNodePtr
    else:
        print("Data does not exist in List")

def OutputAllNodes():
    global List,StartPointer,FreeListPtr
    CurrentNodePtr = StartPointer # start at beginning of list
    if StartPointer == NULLPOINTER:
        print("No data in list")
    while CurrentNodePtr != NULLPOINTER: # while not end of list
        print(CurrentNodePtr, " ",List[CurrentNodePtr].Data," ",List[CurrentNodePtr].Pointer)
        # follow the pointer to the next node
        CurrentNodePtr = List[CurrentNodePtr].Pointer

def GetOption():
    print("1. Add Node - Begining")
    print("2. Add Node - End")
    print("3. Find a node")
    print("4. Delete a node")
    print("5. Output all nodes")
    print("6.Exit")
    response=int(input("Enter the option:"))
    return response

InitialseList()
OutputAllNodes()
response=GetOption()
while response!=6:
    if response==1:
        NewData=input("Enter the new item to insert:")
        InsertNodeAtBeg(NewData)
        OutputAllNodes()
    elif response==2:
        NewData=input("Enter the new item to insert:")
        InsertNodeAtEnd(NewData)
        OutputAllNodes()
    elif response==3:
        NewData=input("Enter the item to search:")
        CurrentNodePtr=FindNode(NewData)
        if CurrentNodePtr==NULLPOINTER:
            print("Data not found")
        else:
            print(NewData," is present at position ",CurrentNodePtr)
    elif response==4:
        NewData=input("Enter the item to delete:")
        DeleteNode(NewData)
        OutputAllNodes()
    elif response==5:
        OutputAllNodes()
    response=GetOption()
    
