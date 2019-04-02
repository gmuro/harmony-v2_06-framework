/*******************************************************************************
* Contains proprietary and confidential information of SEARAN LLC.
* May not be used or disclosed to any other party except in accordance
* with a license from SEARAN LLC.
* Copyright (c) 2011-2016 SEARAN LLC. All Rights Reserved.
*******************************************************************************/

#include "cdbt/bt/bt_std.h"
#include "cdbt/bt/bt_private.h"
#include "cdbt/hci/hci.h"
#include "cdbt/extra/csr/csr.h"
#include "cdbt/extra/csr/patch.h"

#include "script__PB_90_REV6.h"

static const btx_csr_script_t script =
{
	packets,
	PACKET_COUNT,
	6817
};

const btx_csr_script_t* btx_csr_get_script__PB_90_REV6(void)
{
	return &script;
}
