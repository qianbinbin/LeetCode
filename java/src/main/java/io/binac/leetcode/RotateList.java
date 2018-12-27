package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 1->2->3->4->5->NULL, k = 2
 *     Output: 4->5->1->2->3->NULL
 *     Explanation:
 *     rotate 1 steps to the right: 5->1->2->3->4->NULL
 *     rotate 2 steps to the right: 4->5->1->2->3->NULL
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 0->1->2->NULL, k = 4
 *     Output: 2->0->1->NULL
 *     Explanation:
 *     rotate 1 steps to the right: 2->0->1->NULL
 *     rotate 2 steps to the right: 1->2->0->NULL
 *     rotate 3 steps to the right: 0->1->2->NULL
 *     rotate 4 steps to the right: 2->0->1->NULL
 * </blockquote></pre>
 */
public class RotateList {
    public static class Solution1 {
        public ListNode rotateRight(ListNode head, int k) {
            if (k < 0)
                throw new IllegalArgumentException("k must be non-negative");
            if (k == 0) return head;
            int n = 0;
            ListNode p = head;
            while (p != null) {
                p = p.next;
                ++n;
            }
            if (n == 0) return head;
            k %= n;
            if (k == 0) return head;

            ListNode fast = head;
            for (int i = 0; i < k; ++i) fast = fast.next;
            ListNode slow = head;
            while (fast.next != null) {
                fast = fast.next;
                slow = slow.next;
            }
            fast.next = head;
            head = slow.next;
            slow.next = null;
            return head;
        }
    }
}
