/** @file
  Module entry point library for PEIM.

Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __MODULE_ENTRY_POINT_H__
#define __MODULE_ENTRY_POINT_H__

///
/// Declare the EFI/UEFI Specification Revision to which this driver is implemented
///
extern CONST UINT32  _gPeimRevision;

/**
  The entry point of PE/COFF Image for a PEIM.

  This function is the entry point for a PEIM.  This function must call ProcessLibraryConstructorList()
  and ProcessModuleEntryPointList().  The return value from ProcessModuleEntryPointList() is returned.
  If _gPeimRevision is not zero and PeiServices->Hdr.Revision is less than _gPeimRevison, then ASSERT().

  @param  FileHandle  Handle of the file being invoked.
  @param  PeiServices Describes the list of possible PEI Services.

  @retval  EFI_SUCCESS   The PEIM executed normally.
  @retval  !EFI_SUCCESS  The PEIM failed to execute normally.
**/
NO_STACK_COOKIE // MU_CHANGE: Project Mu Runtime Randomized Stack Cookie Support
EFI_STATUS
EFIAPI
_ModuleEntryPoint (
  IN EFI_PEI_FILE_HANDLE     FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices
  );

/**
  Required by the EBC compiler and identical in functionality to _ModuleEntryPoint().

  This function is required to call _ModuleEntryPoint() passing in FileHandle and PeiServices.

  @param  FileHandle  Handle of the file being invoked.
  @param  PeiServices Describes the list of possible PEI Services.

  @retval EFI_SUCCESS  The PEIM executed normally.
  @retval !EFI_SUCCESS The PEIM failed to execute normally.

**/
EFI_STATUS
EFIAPI
EfiMain (
  IN EFI_PEI_FILE_HANDLE     FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices
  );

/**
  Autogenerated function that calls the library constructors for all of the module's
  dependent libraries.

  This function must be called by _ModuleEntryPoint().
  This function calls the set of library constructors for the set of library instances that a
  module depends on. This includes library instances that a module depends on directly and library
  instances that a module depends on indirectly through other libraries.
  This function is autogenerated by build tools and those build tools are responsible for collecting
  the set of library instances, determine which ones have constructors, and calling the library
  constructors in the proper order based upon each of the library instances own dependencies.

  @param  FileHandle   Handle of the file being invoked.
  @param  PeiServices  Describes the list of possible PEI Services.

**/
VOID
EFIAPI
ProcessLibraryConstructorList (
  IN EFI_PEI_FILE_HANDLE     FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices
  );

/**
  Autogenerated function that calls a set of module entry points.

  This function must be called by _ModuleEntryPoint().
  This function calls the set of module entry points.
  This function is autogenerated by build tools and those build tools are responsible
  for collecting the module entry points and calling them in a specified order.

  @param  FileHandle  Handle of the file being invoked.
  @param  PeiServices Describes the list of possible PEI Services.

  @retval EFI_SUCCESS  The PEIM executed normally.
  @retval !EFI_SUCCESS The PEIM failed to execute normally.

**/
EFI_STATUS
EFIAPI
ProcessModuleEntryPointList (
  IN EFI_PEI_FILE_HANDLE     FileHandle,
  IN CONST EFI_PEI_SERVICES  **PeiServices
  );

#endif
