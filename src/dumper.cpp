#include <pch.hpp>

namespace rust
{
    using namespace il2cpp_exports;

    [[noexcept]] std::uintptr_t get_typeinfo_for_klass(const Il2CppClass* klass)
    {
        std::uintptr_t typeinfo = memory::find_field_ptr(klass);

        if (typeinfo == 0u)
        {
            return 0u;
        }

        std::uintptr_t typeinfo_rva = typeinfo - reinterpret_cast<std::uintptr_t>(rust::modules["GameAssembly.dll"]);

        return typeinfo_rva;
    }

    namespace base_networkable
    {
        DEFINE_FIELD_OFFSET(prefab_id);
        DEFINE_FIELD_OFFSET(network_range);
        DEFINE_FIELD_OFFSET(entity_list);
        DEFINE_FIELD_OFFSET(prefab_name);

        void generate()
        {
            Il2CppClass* klass = GET_CLASS("BaseNetworkable");
            if (!klass) return;

            BEGIN_NAMESPACE(base_networkable_static_fields);
            {
                const Il2CppClass* inner_klass = il2cpp::get_inner_static_class(klass);
                if (inner_klass != nullptr)
                {
                    const std::uintptr_t typeinfo_ptr = get_typeinfo_for_klass(inner_klass);

                    if (typeinfo_ptr != 0ull)
                    {
                        ADD_FIELD_MEMBER(base_networkable_static_fields, "typeinfo", typeinfo_ptr);
                    }
                }
            }
            END_NAMESPACE(base_networkable_static_fields);

            BEGIN_NAMESPACE(base_networkable);
            {
                GENERATE_FIELD_MEMBER_BY_NAME(base_networkable, prefab_id, "prefabID", "prefab_id");
                GENERATE_FIELD_MEMBER_BY_NAME(base_networkable, network_range, "networkRange", "network_range");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_networkable, entity_list, "BaseEntity", "entity_list", FIELD_ATTRIBUTE_PUBLIC);
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_networkable, prefab_name, "System.String", "prefab_name", FIELD_ATTRIBUTE_PRIVATE);
            }
            END_NAMESPACE(base_networkable);
        }
    }

    namespace base_player
    {
        DEFINE_FIELD_OFFSET(eyes);
        DEFINE_FIELD_OFFSET(inventory);
        DEFINE_FIELD_OFFSET(player_model);
        DEFINE_FIELD_OFFSET(input);
        DEFINE_FIELD_OFFSET(movement);
        DEFINE_FIELD_OFFSET(collision);
        DEFINE_FIELD_OFFSET(player_flags);
        DEFINE_FIELD_OFFSET(display_name);

        void generate()
        {
            Il2CppClass* klass = GET_CLASS("BasePlayer");
            if (!klass) return;

            BEGIN_NAMESPACE(base_player);
            {
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, eyes, "PlayerEyes", "eyes");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, inventory, "PlayerInventory", "inventory");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, player_model, "PlayerModel", "player_model");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, input, "PlayerInput", "input");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, movement, "BaseMovement", "movement");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, collision, "BaseCollision", "collision");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, player_flags, "PlayerFlags", "player_flags");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_player, display_name, "System.String", "display_name", FIELD_ATTRIBUTE_FAMILY);
            }
            END_NAMESPACE(base_player);
        }
    }

    namespace base_entity
    {
        DEFINE_FIELD_OFFSET(model);
        DEFINE_FIELD_OFFSET(bounds);
        DEFINE_FIELD_OFFSET(flags);

        void generate()
        {
            Il2CppClass* klass = GET_CLASS("BaseEntity");
            if (!klass) return;

            BEGIN_NAMESPACE(base_entity);
            {
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_entity, model, "Model", "model");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_entity, bounds, "Bounds", "bounds");
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(base_entity, flags, "Flags", "flags");
            }
            END_NAMESPACE(base_entity);
        }
    }

    namespace main_camera
    {
        DEFINE_FIELD_OFFSET(instance);
        DEFINE_FIELD_OFFSET(camera_transform);

        void generate()
        {
            Il2CppClass* klass = GET_CLASS("MainCamera");
            if (!klass) return;

            BEGIN_NAMESPACE(main_camera);
            {
                const std::uintptr_t typeinfo_ptr = get_typeinfo_for_klass(klass);

                if (typeinfo_ptr != 0ull)
                {
                    ADD_FIELD_MEMBER(main_camera, "typeinfo", typeinfo_ptr);
                    BREAK_LINE;
                }

                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(main_camera, instance, "Camera", "instance", FIELD_ATTRIBUTE_STATIC);
                GENERATE_FIELD_MEMBER_BY_FIELD_CLASS(main_camera, camera_transform, "Transform", "camera_transform", FIELD_ATTRIBUTE_STATIC);
            }
            END_NAMESPACE(main_camera);
        }
    }
}