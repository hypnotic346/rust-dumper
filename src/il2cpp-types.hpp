#pragma once

#include <cstdint>
#include <cstddef>

#define __int8  char
#define __int16 short
#define __int32 int
#define __int64 long long

struct Il2CppClass;
struct Il2CppType;
struct Il2CppImage;
struct Il2CppAssembly;
struct Il2CppAssemblyName;
struct Il2CppGenericClass;
struct Il2CppGenericInst;
struct Il2CppGenericMethod;
struct Il2CppInteropData;
struct Il2CppCodeGenModule;
struct Il2CppNameToTypeHandleHashTable;
struct Il2CppArrayType;
struct Il2CppString;
struct Il2CppArray;
struct Il2CppArrayBounds;
struct Il2CppRuntimeInterfaceOffsetPair;
struct Il2CppGuid;
struct Il2CppIUnknown;
struct MethodInfo;
struct FieldInfo;
struct EventInfo;
struct PropertyInfo;
struct MonitorData;
struct GenericParameterFlags;
union  Il2CppRGCTXData;
struct VirtualInvokeData;

struct ___Il2CppMetadataTypeHandle;
struct ___Il2CppMetadataGenericContainerHandle;
struct ___Il2CppMetadataMethodHandle;
struct ___Il2CppMetadataImageHandle;

typedef unsigned __int64 il2cpp_array_size_t;

using Il2CppException = void*;
using Il2CppThread = void*;

struct Il2CppObject
{
    union
    {
        Il2CppClass* klass;
        Il2CppClass* vtable;
    } ___u0;
    MonitorData* monitor;
};

struct Il2CppAppDomainSetup
{
    Il2CppObject object;
    Il2CppString* application_base;
    Il2CppString* application_name;
    Il2CppString* cache_path;
    Il2CppString* configuration_file;
    Il2CppString* dynamic_base;
    Il2CppString* license_file;
    Il2CppString* private_bin_path;
    Il2CppString* private_bin_path_probe;
    Il2CppString* shadow_copy_directories;
    Il2CppString* shadow_copy_files;
    unsigned __int8 publisher_policy;
    unsigned __int8 path_changed;
    int loader_optimization;
    unsigned __int8 disallow_binding_redirects;
    unsigned __int8 disallow_code_downloads;
    Il2CppObject* activation_arguments;
    Il2CppObject* domain_initializer;
    Il2CppObject* application_trust;
    Il2CppArray* domain_initializer_args;
    unsigned __int8 disallow_appbase_probe;
    Il2CppArray* configuration_bytes;
    Il2CppArray* serialized_non_primitives;
};

struct Il2CppMarshalByRefObject
{
    Il2CppObject obj;
    Il2CppObject* identity;
};

struct Il2CppAppContext
{
    Il2CppObject obj;
    int domain_id;
    int context_id;
    void* static_data;
};

struct Il2CppDomain;

struct Il2CppAppDomain
{
    Il2CppMarshalByRefObject mbr;
    Il2CppDomain* data;
};

struct Il2CppDomain
{
    Il2CppAppDomain* domain;
    Il2CppAppDomainSetup* setup;
    Il2CppAppContext* default_context;
    Il2CppObject* ephemeron_tombstone;
    const char* friendly_name;
    unsigned int domain_id;
    volatile int threadpool_jobs;
    void* agent_info;
};

struct Il2CppGenericContext
{
    const Il2CppGenericInst* class_inst;
    const Il2CppGenericInst* method_inst;
};

struct Il2CppGenericClass
{
    const Il2CppType* type;
    Il2CppGenericContext context;
    Il2CppClass* cached_class;
};

struct Il2CppType
{
    union
    {
        void* dummy;
        int                                      __klassIndex;
        const ___Il2CppMetadataTypeHandle* typeHandle;
        const Il2CppType* type;
        Il2CppArrayType* array;
        int                                      __genericParameterIndex;
        const ___Il2CppMetadataGenericContainerHandle* genericParameterHandle;
        Il2CppGenericClass* generic_class;
    } data;
    unsigned int bits;
};

struct Il2CppArrayType
{
    const Il2CppType* etype;
    unsigned __int8   rank;
    unsigned __int8   numsizes;
    unsigned __int8   numlobounds;
    int* sizes;
    int* lobounds;
};

const struct __declspec(align(4)) Il2CppImage
{
    const char* name;
    const char* nameNoExt;
    Il2CppAssembly* assembly;
    unsigned int                         typeCount;
    unsigned int                         exportedTypeCount;
    unsigned int                         customAttributeCount;
    const ___Il2CppMetadataImageHandle* metadataHandle;
    Il2CppNameToTypeHandleHashTable* nameToClassHashTable;
    const Il2CppCodeGenModule* codeGenModule;
    unsigned int                         token;
    unsigned __int8                      dynamic;
};

struct __declspec(align(8)) Il2CppAssemblyName
{
    const char* name;
    const char* culture;
    const unsigned __int8* public_key;
    unsigned int         hash_alg;
    int                  hash_len;
    unsigned int         flags;
    int                  major;
    int                  minor;
    int                  build;
    int                  revision;
    unsigned __int8      public_key_token[8];
};

struct Il2CppAssembly
{
    Il2CppImage* image;
    unsigned int      token;
    int               referencedAssemblyStart;
    int               referencedAssemblyCount;
    Il2CppAssemblyName aname;
};

struct Il2CppInteropData
{
    void(__fastcall* delegatePInvokeWrapperFunction)();
    void(__fastcall* pinvokeMarshalToNativeFunction)(void*, void*);
    void(__fastcall* pinvokeMarshalFromNativeFunction)(void*, void*);
    void(__fastcall* pinvokeMarshalCleanupFunction)(void*);
    Il2CppIUnknown* (__fastcall* createCCWFunction)(Il2CppObject*);
    const Il2CppGuid* guid;
    const Il2CppType* type;
};

const union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
};

const struct __declspec(align(8)) MethodInfo
{
    void(__fastcall* methodPointer)();
    void(__fastcall* virtualMethodPointer)();
    void(__fastcall* invoker_method)(void(__fastcall*)(), const MethodInfo*, void*, void**, void*);
    const char* name;
    Il2CppClass* klass;
    const Il2CppType* return_type;
    const Il2CppType** parameters;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const ___Il2CppMetadataMethodHandle* methodMetadataHandle;
    } ___u7;
    union
    {
        const Il2CppGenericMethod* genericMethod;
        const ___Il2CppMetadataGenericContainerHandle* genericContainerHandle;
    } ___u8;
    unsigned int     token;
    unsigned __int16 flags;
    unsigned __int16 iflags;
    unsigned __int16 slot;
    unsigned __int8  parameters_count;
    unsigned __int8  is_generic : 1;
    unsigned __int8  is_inflated : 1;
    unsigned __int8  wrapper_type : 1;
    unsigned __int8  has_full_generic_sharing_signature : 1;
    unsigned __int8  is_unmanaged_callers_only : 1;
};

struct FieldInfo
{
    const char* name;
    const Il2CppType* type;
    Il2CppClass* parent;
    int               offset;
    unsigned int      token;
};

const struct __declspec(align(8)) EventInfo
{
    const char* name;
    const Il2CppType* eventType;
    Il2CppClass* parent;
    const MethodInfo* add;
    const MethodInfo* remove;
    const MethodInfo* raise;
    unsigned int      token;
};

const struct PropertyInfo
{
    Il2CppClass* parent;
    const char* name;
    const MethodInfo* get;
    const MethodInfo* set;
    unsigned int      attrs;
    unsigned int      token;
};

struct __declspec(align(8)) Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int          offset;
};

const struct GenericParameterFlags
{
    unsigned int      count;
    unsigned __int16  flags[];
};

struct VirtualInvokeData
{
    void(__fastcall* methodPtr)();
    const MethodInfo* method;
};

struct MonitorData;

struct Il2CppClass
{
    const Il2CppImage* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType                                   byval_arg;
    Il2CppType                                   this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    Il2CppGenericClass* generic_class;
    const ___Il2CppMetadataTypeHandle* typeMetadataHandle;
    const Il2CppInteropData* interopData;
    Il2CppClass* klass;
    FieldInfo* fields;
    const EventInfo* events;
    const PropertyInfo* properties;
    const MethodInfo** methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;

    void* static_fields;
    union
    {
        const Il2CppRGCTXData* rgctx_data;
        const GenericParameterFlags* genericParameterFlags;
    } ___u22;

    Il2CppClass** typeHierarchy;
    void* unity_user_data;
    void* initializationExceptionGCHandle;
    unsigned int                                 cctor_started;
    unsigned int                                 cctor_finished_or_no_cctor;
    unsigned __int64                             cctor_thread;
    const ___Il2CppMetadataGenericContainerHandle* genericContainerHandle;
    unsigned int                                 instance_size;
    unsigned int                                 stack_slot_size;
    unsigned int                                 actualSize;
    unsigned int                                 element_size;
    int                                          native_size;
    unsigned int                                 static_fields_size;
    unsigned int                                 thread_static_fields_size;
    int                                          thread_static_fields_offset;
    unsigned int                                 flags;
    unsigned int                                 token;
    unsigned __int16                             method_count;
    unsigned __int16                             property_count;
    unsigned __int16                             field_count;
    unsigned __int16                             event_count;
    unsigned __int16                             nested_type_count;
    unsigned __int16                             vtable_count;
    unsigned __int16                             interfaces_count;
    unsigned __int16                             interface_offsets_count;
    unsigned __int8                              typeHierarchyDepth;
    unsigned __int8                              genericRecursionDepth;
    unsigned __int8                              rank;
    unsigned __int8                              minimumAlignment;
    unsigned __int8                              packingSize;
    unsigned __int8                              initialized_and_no_error : 1;
    unsigned __int8                              initialized : 1;
    unsigned __int8                              enumtype : 1;
    unsigned __int8                              nullabletype : 1;
    unsigned __int8                              is_generic : 1;
    unsigned __int8                              has_references : 1;
    unsigned __int8                              init_pending : 1;
    unsigned __int8                              size_init_pending : 1;
    unsigned __int8                              size_inited : 1;
    unsigned __int8                              has_finalize : 1;
    unsigned __int8                              has_cctor : 1;
    unsigned __int8                              is_blittable : 1;
    unsigned __int8                              is_import_or_windows_runtime : 1;
    unsigned __int8                              is_vtable_initialized : 1;
    unsigned __int8                              is_byref_like : 1;

    VirtualInvokeData                            vtable[];
};

struct __declspec(align(8)) Il2CppArrayBounds
{
    unsigned __int64 length;
    int              lower_bound;
};

struct Il2CppArray : Il2CppObject
{
    Il2CppArrayBounds* bounds;
    unsigned __int64   max_length;
};

struct __declspec(align(8)) Il2CppString : Il2CppObject
{
    int     length;
    wchar_t chars[];
};