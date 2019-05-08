//输入两个链表，找出他们的第一个公共节点
int getLength(struct ListNode* head) {
	int len = 0;
	for (struct ListNode* pCur = head; pCur; pCur = pCur->next)
		len++;
	return len;
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	int lenA = getLength(headA);
	int lenB = getLength(headB);
	struct ListNode* longer = headA;
	struct ListNode* shorter = headB;
	int diff = lenA - lenB;
	if (lenB > lenA) {
		longer = headB;
		shorter = headA;
		diff = lenB - lenA;
	}
	for (int i = 0; i < diff; ++i) {
		longer = longer->next;
	}
	while (longer != shorter) {
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
}