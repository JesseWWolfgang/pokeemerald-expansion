# feature/forbidden-shop-items

Adds some internal code for providing the ability to prevent certain items from appearing in Pokemarts.

To specify forbidden items, return `TRUE` for it in the following function at `src/shop.c:340`. For example, to remove the 20HP potion from all shops:

```c 
static bool8 IsForbiddenShopItem(const u16 itemId)
{
    switch (itemId)
    {
        case ITEM_POTION:
            return TRUE;
    }
    return FALSE;
}
```