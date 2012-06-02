
#include "LedgerFormats.h"

#define S_FIELD(x) sf##x, #x

LedgerEntryFormat LedgerFormats[]=
{
	{ "AccountRoot", ltACCOUNT_ROOT, {
		{ S_FIELD(Flags),				STI_UINT32,  SOE_FLAGS,    0 },
		{ S_FIELD(Account),				STI_ACCOUNT, SOE_REQUIRED, 0 },
		{ S_FIELD(Sequence),			STI_UINT32,  SOE_REQUIRED, 0 },
		{ S_FIELD(Balance),				STI_AMOUNT,  SOE_REQUIRED, 0 },
		{ S_FIELD(LastReceive),			STI_UINT32,  SOE_REQUIRED, 0 },
		{ S_FIELD(LastTxn),				STI_UINT32,  SOE_REQUIRED, 0 },
		{ S_FIELD(AuthorizedKey),		STI_ACCOUNT, SOE_IFFLAG,   1 },
		{ S_FIELD(EmailHash),			STI_HASH128, SOE_IFFLAG,   2 },
		{ S_FIELD(WalletLocator),		STI_HASH256, SOE_IFFLAG,   4 },
		{ S_FIELD(MessageKey),			STI_VL,		 SOE_IFFLAG,   8 },
		{ S_FIELD(TransitRate),			STI_UINT32,  SOE_IFFLAG,  16 },
		{ S_FIELD(Extensions),			STI_TL,		 SOE_IFFLAG,   0x01000000 },
		{ sfInvalid, NULL,				STI_DONE,	 SOE_NEVER,    -1 } }
	},
	{ "DirectoryRoot", ltDIR_ROOT, {
		{ S_FIELD(Flags),				STI_UINT32,		SOE_FLAGS,    0 },
		{ S_FIELD(FirstNode),			STI_UINT64,		SOE_REQUIRED, 0 },
		{ S_FIELD(LastNode),			STI_UINT64,		SOE_REQUIRED, 0 },
		{ S_FIELD(Extensions),			STI_TL,			SOE_IFFLAG,   0x01000000 },
		{ sfInvalid, NULL,				STI_DONE,		SOE_NEVER,    -1 } }
	},
	{ "DirectoryNode", ltDIR_NODE, {
		{ S_FIELD(Flags),				STI_UINT32,		SOE_FLAGS,    0 },
		{ S_FIELD(Indexes),				STI_VECTOR256,	SOE_REQUIRED, 0 },
		{ S_FIELD(Extensions),			STI_TL,			SOE_IFFLAG,   0x01000000 },
		{ sfInvalid, NULL,				STI_DONE,		SOE_NEVER,    -1 } }
	},
	{ "GeneratorMap", ltGENERATOR_MAP, {
		{ S_FIELD(Flags),				STI_UINT32,		SOE_FLAGS,	  0 },
		{ S_FIELD(GeneratorID),			STI_HASH160,	SOE_REQUIRED, 0 },
		{ S_FIELD(Generator),			STI_VL,			SOE_REQUIRED, 0 },
		{ S_FIELD(Extensions),			STI_TL,			SOE_IFFLAG,   0x01000000 },
		{ sfInvalid, NULL,				STI_DONE,		SOE_NEVER,	  -1 } }
	},
	{ "Nickname", ltNICKNAME, {
		{ S_FIELD(Flags),				STI_UINT32,  SOE_FLAGS,    0 },
		{ S_FIELD(Nickname),			STI_HASH256, SOE_REQUIRED, 0 },
		{ S_FIELD(Account),				STI_ACCOUNT, SOE_REQUIRED, 0 },
		{ S_FIELD(MinimumOffer),		STI_AMOUNT,  SOE_IFFLAG,   1 },
		{ S_FIELD(OfferCurrency),		STI_HASH160, SOE_IFFLAG,   2 },
		{ S_FIELD(Extensions),			STI_TL,		 SOE_IFFLAG,   0x01000000 },
		{ sfInvalid, NULL,				STI_DONE,	 SOE_NEVER,    -1 } }
	},
	{ "RippleState", ltRIPPLE_STATE, {
		{ S_FIELD(Flags),				STI_UINT32,  SOE_FLAGS,    0 },
		{ S_FIELD(Balance),				STI_AMOUNT,  SOE_REQUIRED, 0 },
		{ S_FIELD(LowID),				STI_ACCOUNT, SOE_REQUIRED, 0 },
		{ S_FIELD(LowLimit),			STI_AMOUNT,  SOE_REQUIRED, 0 },
		{ S_FIELD(HighID),				STI_ACCOUNT, SOE_REQUIRED, 0 },
		{ S_FIELD(HighLimit),			STI_AMOUNT,  SOE_REQUIRED, 0 },
		{ S_FIELD(AcceptRate),			STI_UINT32,  SOE_IFFLAG,   1 },
		{ S_FIELD(Extensions),			STI_TL,      SOE_IFFLAG,   0x01000000 },
		{ sfInvalid, NULL,				STI_DONE,    SOE_NEVER,    -1 } }
	},
	{ NULL, ltINVALID }
};

LedgerEntryFormat* getLgrFormat(LedgerEntryType t)
{
	LedgerEntryFormat* f = LedgerFormats;
	while(f->t_name != NULL)
	{
		if(f->t_type == t) return f;
		++f;
	}
	return NULL;
}
// vim:ts=4
