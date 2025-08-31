#include <ntddk.h>
#include <wdf.h>


void DriverUnload(_In_ PDRIVER_OBJECT DriverObject)
{
    UNREFERENCED_PARAMETER(DriverObject);
    DbgPrint("[KMDFDriver3] Driver descarregado!\n");
}

extern "C" NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = DriverUnload;

    DbgPrint("[KMDFDriver3] Driver carregado com sucesso!\n");

    return STATUS_SUCCESS;
}
