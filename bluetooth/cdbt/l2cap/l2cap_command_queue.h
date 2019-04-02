/*******************************************************************************
* Contains proprietary and confidential information of SEARAN LLC.
* May not be used or disclosed to any other party except in accordance
* with a license from SEARAN LLC.
* Copyright (c) 2011-2016 SEARAN LLC. All Rights Reserved.
*
* SEARAN LLC is the exclusive licensee and developer of dotstack with
* all its modifications and enhancements.
*
* Contains proprietary and confidential information of CandleDragon and
* may not be used or disclosed to any other party except in accordance
* with a license from SEARAN LLC.
* Copyright (c) 2009, 2010, 2011 CandleDragon. All Rights Reserved.
*******************************************************************************/

#ifndef __L2CAP_COMMAND_QUEUE_H
#define __L2CAP_COMMAND_QUEUE_H

#include "cdbt/utils/queue.h"

#ifdef __cplusplus
extern "C" {
#endif

#define L2CAP_MAX_CMD_QUEUE_LEN 5

struct _bt_l2cap_mgr_s;

void _bt_l2cap_send_commands_from_queue(struct _bt_l2cap_mgr_s* pmgr);
void _bt_l2cap_notify_and_remove(struct _bt_l2cap_mgr_s* pmgr, bt_l2cap_cmd_header_p pcmd);

#ifdef __cplusplus
}
#endif

#endif //__L2CAP_COMMAND_QUEUE_H
