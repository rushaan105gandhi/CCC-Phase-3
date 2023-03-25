def getNode(head, position):
    if not head:
        return None
    if not head.next:
        return head.data
    lst_len = 0
    ptr = head
    while ptr.next:
        lst_len += 1
        ptr = ptr.next
    while lst_len > position:
        head = head.next
        lst_len -= 1
    return head.data