#include <stdlib.h>
#include "detect_ll_loop.h"

int detect_ll_loop(LinkedListT* thisLl)
{
    NodeT* slow = thisLl->head;
    if(slow == NULL)
        return FALSE;
    NodeT* fast = thisLl->head->next;
    if(fast == NULL)
        return FALSE;

    if (slow == fast)
        return TRUE;
    slow = slow->next;
    if(slow == NULL)
        return FALSE;
    else
    {
        fast = fast->next->next;
        while((slow != fast) && (fast->next!=NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow==fast)
            return TRUE;
        else
            return FALSE;

    }
}
