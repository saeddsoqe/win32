/* ###*B*###
 * Erika Enterprise, version 3
 * 
 * Copyright (C) 2017 - 2018 Evidence s.r.l.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License, version 2, for more details.
 * 
 * You should have received a copy of the GNU General Public License,
 * version 2, along with this program; if not, see
 * < www.gnu.org/licenses/old-licenses/gpl-2.0.html >.
 * 
 * This program is distributed to you subject to the following
 * clarifications and special exceptions to the GNU General Public
 * License, version 2.
 * 
 * THIRD PARTIES' MATERIALS
 * 
 * Certain materials included in this library are provided by third
 * parties under licenses other than the GNU General Public License. You
 * may only use, copy, link to, modify and redistribute this library
 * following the terms of license indicated below for third parties'
 * materials.
 * 
 * In case you make modified versions of this library which still include
 * said third parties' materials, you are obligated to grant this special
 * exception.
 * 
 * The complete list of Third party materials allowed with ERIKA
 * Enterprise version 3, together with the terms and conditions of each
 * license, is present in the file THIRDPARTY.TXT in the root of the
 * project.
 * ###*E*### */

/** \file   ee.h
 *  \brief  Main Collector.
 *
 *  This files is the main collector in Erika Enterprise.
 *
 *  \author Michele Pes
 *  \date   2017
 */
/*this for x86*/
#ifndef OSEE_H
#define OSEE_H

//this header is common between all files
/*This files is the collector between OS Configuration and Application
 *  Configuration.*/
//it contains include generated headers
#include "ee_cfg.h"
#include "ee_arch_override.h"
/*  This files contains all common utilities available in Erika Enterprise.
*
*  \note Those utilities must be abstracted in order to become platform
*        and compiler independend. \n*/
#include "ee_utils.h"
#include "ee_compiler.h"
//this file has the name in all files but different imple
/*This files contains all types and symbols for a specific Architecture in
 *  Erika Enterprise.
 *
 *  \note COULD BE raplaced by AUTOSAR Type definition paradigm or being the
 *        implementation.*/
#include "ee_platform_types.h"
#include "ee_hal.h"
#include "ee_api.h"
#if (defined(OSEE_ASSERT))
#include "ee_assert.h"
#endif  /* OSEE_ASSERT */
#if (!defined(OS_EE_BUILD))
#include "ee_declcfg.h"
#endif /* !OS_EE_BUILD */
#include "ee_print.h"
#endif /* !OSEE_H */
